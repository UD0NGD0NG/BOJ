#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dp[1'005]{}; string ans[2] = { "CY", "SK" };
	dp[1] = 1, dp[2] = 0, dp[3] = 1, dp[4] = 1, dp[5] = 1, dp[6] = 1, dp[7] = 0, dp[8] = 1;
	for (int i = 9; i <= 1000; i++) dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);

	int n; cin >> n;
	cout << ans[dp[n]];
}