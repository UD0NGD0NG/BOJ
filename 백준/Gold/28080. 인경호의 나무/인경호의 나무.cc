#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct node {
	int data;
	int leftIdx;
	int rightIdx;
	node(int data, int leftIdx, int rightIdx) {
		this->data = data;
		this->leftIdx = leftIdx;
		this->rightIdx = rightIdx;
	}
};

const int MOD = 1000000007;
vector<int> result(1);
vector<node*> tree(1);
vector<long long> fact(2000, 1);

ll binomialCoeff(ll n, ll k) {
	vector<vector<ll>> C(n + 1, vector<ll>(k + 1));

	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	return C[n][k];
}

ll C(pair<int, pair<int, int>>& x) {
	int r = x.second.second - x.second.first - 1;
	int n = x.first;

	return binomialCoeff(r, n);
}

void inorder(int idx) {
	if (tree[idx]->leftIdx != -1) {
		inorder(tree[idx]->leftIdx);
	}

	result.push_back(tree[idx]->data);

	if (tree[idx]->rightIdx != -1) {
		inorder(tree[idx]->rightIdx);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fact[1] = 1;
	for (int i = 2; i < fact.size(); i++) {
		fact[i] = fact[i - 1] * i;
	}

	vector<pair<int, pair<int, int>>> v; // -1개수, 그 앞, 그 뒤
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		tree.push_back(new node(a, b, c));
	}

	inorder(1);
	
	result.push_back(m + 1);
	bool flag = false; // -1범위인가
	int cnt = 0, prev, next;
	for (int i = 1; i < result.size(); i++) {
		if (flag) {
			if (result[i] != -1) {
				flag = false;
				next = result[i];

				v.push_back(make_pair(cnt, make_pair(prev, next)));
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
		else {
			if (result[i] == -1) {
				flag = true;
				prev = result[i - 1];
				cnt = 1;
			}
		}
	}

	ll ans = 1;
	for (auto x : v) {
		ans *= C(x);
		ans %= MOD;
	}

	cout << ans;
}