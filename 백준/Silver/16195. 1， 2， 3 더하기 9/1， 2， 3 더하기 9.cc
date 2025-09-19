#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1'000'000'009;

int main() {
	vector<vector<long long>> v(1'005, vector<long long>(1'005, 0));
	v[1][1] = 1;
	v[2][1] = 1; v[2][2] = 1;
	v[3][1] = 1; v[3][2] = 2; v[3][3] = 1;

	for (int i = 4; i <= 1'000; i++) {
		for (int j = 1; j <= i; j++) {
			v[i][j] = (v[i - 1][j - 1] + v[i - 2][j - 1] + v[i - 3][j - 1]) % MOD;
		}
	}

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		long long ans = 0;
		for (int i = 1; i <= m; i++) ans += v[n][i]; ans %= MOD;
		cout << ans << '\n';
	}
}