#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<vector<ll>> v(4, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> v[j][i];
		}
	}

	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a.push_back(v[0][i] + v[1][j]); // 배열 A와 배열 B에서 1개씩 뽑아 해당 경우의 합을 저장
			b.push_back(v[2][i] + v[3][j]); // 배열 C와 배열 D에서 1개씩 뽑아 해당 경우의 합을 저장
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ll left = 0, right = b.size() - 1;
		while (left <= right) {
			ll mid = (left + right) / 2;

			if (a[i] + b[mid] == 0) { // a + b가 0이면 A, B, C, D에서 하나씩 뽑았을때 0인경우와 같은 의미
				ans += upper_bound(b.begin(), b.end(), b[mid]) - lower_bound(b.begin(), b.end(), b[mid]); // a[x]와 a[x+1]이 같은값을 갔더라도 a, b가 다르므로 각각 세줘야함
				break;
			}
			else if (a[i] + b[mid] > 0) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	cout << ans;
}