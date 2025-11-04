#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dp[1'005]{}; string ans[2] = { "CY", "SK" };
	dp[1] = 0, dp[2] = 1, dp[3] = 0, dp[4] = 1;
	for (int i = 5; i <= 1000; i++) dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);

	int n; cin >> n;
	cout << ans[dp[n]];
}