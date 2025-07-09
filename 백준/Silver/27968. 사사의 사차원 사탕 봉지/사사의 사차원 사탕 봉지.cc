#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<ll> cum(1, 0);
	for (int i = 0; i < m; i++) {
		ll a; cin >> a;
		cum.push_back(a + cum.back());
	}

	for (int i = 0; i < n; i++) {
		ll b; cin >> b;
		if (b > cum.back()) {
			cout << "Go away!\n";
		}
		else {
			ll left = 1, right = m;
			while (left <= right) {
				ll mid = (left + right) / 2;
				if (b == cum[mid] || (cum[mid - 1] < b && b < cum[mid])) {
					cout << mid << '\n';
					break;
				}
				else if (b > cum[mid]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
	}
}