#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, c; cin >> n >> c;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	bool flag = false;

	for (ll i = 0; i < n; i++) {
		if (v[i] == c) { // 1개로 딱 맞게 물건을 가져갈 수 있는 경우
			flag = true;
			break;
		}
	}

	if (!flag) { // 2개로 무게에 딱 맞게 물건을 가져갈 수 있는 경우
		for (ll i = 0; i < n; i++) {
			bool f = false;
			ll left = 0, right = n - 1;

			while (left <= right) {
				ll mid = (left + right) / 2;

				if (v[i] + v[mid] == c) {
					if (i == mid) break;
					else {
						flag = true;
						f = true;
						break;
					}
				}
				else if (v[i] + v[mid] > c) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}

			if (f) break;
		}
	}

	if (!flag) { // 3개로 무게에 딱 맞게 물건을 가져갈 수 있는 경우
		for (ll i = 0; i < n; i++) {
			bool ff = false;
			for (ll j = i + 1; j < n; j++) {
				bool f = false;
				ll left = 0, right = n - 1;
				while (left <= right) {
					ll mid = (left + right) / 2;

					if (v[i] + v[j] + v[mid] == c) {
						if (mid == i || mid == j) break;
						else {
							f = true;
							ff = true;
							flag = true;
							break;
						}
					}
					else if (v[i] + v[j] + v[mid] > c) {
						right = mid - 1;
					}
					else {
						left = mid + 1;
					}
				}

				if (f) break;
			}

			if (ff) break;
		}
	}

	cout << flag;
}