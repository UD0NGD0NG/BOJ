#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'000;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll dp[105][10]{}; for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 9; j++) {
			dp[i][j] = dp[i - 1][j + 1];
		}
		for (int j = 1; j < 10; j++) {
			dp[i][j] += dp[i - 1][j - 1] % MOD;
		}
	}
	
	ll n, ans = 0; cin >> n;
	for (int i = 0; i < 10; i++) ans += dp[n][i] % MOD;
	cout << ans % MOD;
}