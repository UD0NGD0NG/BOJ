#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dp[10]{}; string ans[2] = { "CY", "SK" };
	dp[0] = 0, dp[1] = 1, dp[2] = 0, dp[3] = 1, dp[4] = 1;
	for (int i = 5; i < 10; i++) dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);

	unsigned long long n; cin >> n;
	cout << ans[dp[n % 7]];
}