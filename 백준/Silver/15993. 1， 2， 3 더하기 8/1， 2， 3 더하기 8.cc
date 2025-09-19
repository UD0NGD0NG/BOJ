#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1'000'000'009;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll v1[100'005]; v1[1] = 1, v1[2] = 1; v1[3] = 2;
	ll v2[100'005]; v2[1] = 0, v2[2] = 1, v2[3] = 2;

	for (int i = 4; i < 100'001; i++) {
		v1[i] = (v2[i - 1] + v2[i - 2] + v2[i - 3]) % MOD;
		v2[i] = (v1[i - 1] + v1[i - 2] + v1[i - 3]) % MOD;
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		cout << v1[n] << ' ' << v2[n] << '\n';
	}
}