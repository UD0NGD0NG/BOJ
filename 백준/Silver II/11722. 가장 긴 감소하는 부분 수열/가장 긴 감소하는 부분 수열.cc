#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[1000] = {};
	int dp[1000] = {};
	int n, i, j, max, ans;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++) {
		max = 0;
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[i] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	ans = dp[0];
	for (i = 1; i < n; i++)
		if (ans < dp[i])
			ans = dp[i];
	cout << ans;
}