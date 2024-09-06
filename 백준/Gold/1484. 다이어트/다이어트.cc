#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool flag = false;

	ll g; cin >> g;

	for (ll i = 1; i <= g; i++) { // 오름차순 탐색
		ll left = 1, right = i - 1;
		while (left <= right) {
			ll mid = (left + right) / 2;

			ll res = (i - mid) * (i + mid); // i^2 - mid^2
			if (res == g) {
				cout << i << '\n';
				flag = true;
				break; // 가능한 경우가 있으면 추가 탐색없이 다음 케이스로
			}
			else if (res > g) {
				left = mid + 1; // i^2 - mid^2 가 더 크면 mid값이 더 커져야 함
			}
			else {
				right = mid - 1; // i^2 - mid^2 가 더 작으면 mid값이 더 작아져야 함
			}
		}
	}

	if (!flag) cout << -1; // 가능한 몸무게가 없는 경우
}