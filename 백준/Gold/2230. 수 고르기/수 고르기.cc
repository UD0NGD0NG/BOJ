#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	vector<ll> a(n); for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	ll ans = a.back() - a.front();
	for (int i = 0; i < n; i++) {
		ll left = i, right = n - 1;
		while (left <= right) {
			ll mid = (left + right) / 2;

			if (a[mid] - a[i] >= m) {
				ans = min(ans, a[mid] - a[i]);
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	cout << ans;
}