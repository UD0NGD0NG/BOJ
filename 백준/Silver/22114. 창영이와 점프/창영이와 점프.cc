#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;

	int ans1 = 1, ans2 = 1, ans = 0;
	for (int i = 1; i < n; i++) {
		int l; cin >> l;
		if (l > k) {
			ans = max(ans, ans2);
			ans2 = ans1;
			ans1 = 1;
		}
		else {
			ans1++;
		}

		ans2++;
	}

	cout << max(ans, max(ans1, ans2));
}