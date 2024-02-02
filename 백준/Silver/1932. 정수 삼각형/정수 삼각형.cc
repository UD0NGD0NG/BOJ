#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, i, j, ans = 0;
	cin >> n;
	int arr[500][500];
	int dp[500][500];
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			cin >> arr[i][j];
	dp[0][0] = arr[0][0];
	for (i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
	}
	for (i = 2; i < n; i++)
		for (j = 1; j < i; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
	for (i = 0; i < n; i++) // 아래층 까지의 합 중 가장 큰 값을 판정
		if (ans < dp[n - 1][i])
			ans = dp[n - 1][i];
	cout << ans;
}