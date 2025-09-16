#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll target = 1;
bool F = false;

void backtracking(vector<int>& v, int n) {
	if (F) return;

	if (v.size() == n) {
		ll cur = 1;
		for (ll l : v) cur *= l;

		if (cur > target) {
			F = true;
			for (ll l : v) {
				cout << l << ' ';
			}
		}

		return;
	}

	for (int i = 1; i <= 9; i++) {
		v.push_back(i);
		backtracking(v, n);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	bool flag = true;
	
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		target *= a;
		if (a != 9) flag = false;
	}

	if (flag) {
		cout << -1;
	}
	else {
		vector<int> v;
		backtracking(v, n);
	}
}