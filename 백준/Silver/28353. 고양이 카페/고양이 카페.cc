#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> w(n); for (int i = 0; i < n; i++) cin >> w[i];

	sort(w.begin(), w.end());

	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		if (w[l] + w[r] <= k) {
			ans++;
			l++, r--;
		}
		else {
			r--;
		}
	}

	cout << ans;
}