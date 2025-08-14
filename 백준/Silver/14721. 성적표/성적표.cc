#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		v[i] = { x, y };
	}

	ll rss = LLONG_MAX;
	ll a = 1, b = 1;
	for (ll i = 1; i <= 100; i++) {
		for (ll j = 1; j <= 100; j++) {
			ll r = 0;
			for (int k = 0; k < n; k++) {
				r += (v[k].second - (i * v[k].first + j)) * (v[k].second - (i * v[k].first + j));
			}

			if (rss >= r) {
				rss = r, a = i, b = j;
			}
		}
	}

	cout << a << ' ' << b;
}