#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0, n, l, r, x;
vector<int> A, cur;

void backtracking(int i, int curSum) {
	if (cur.size() >= 2 && l <= curSum && curSum <= r && (cur.back() - cur.front()) >= x) {
		ans++;
	}
	for (int j = i + 1; j < n; j++) {
		cur.push_back(A[j]);
		backtracking(j, curSum + A[j]);
		cur.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		cur.push_back(A[i]);
		backtracking(i, A[i]);
		cur.pop_back();
	}

	cout << ans;
}