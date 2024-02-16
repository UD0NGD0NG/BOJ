#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[1000] = {}; // 입력받은 수열을 저장
	int dp[1000] = {}; // 해당 index가 부분수열의 마지막 원소라고 가정하였을 때 해당 부분 순열의 크기를 저장
	int n, i, j, max, ans;
	cin >> n;
	
	for (i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = arr[0];
	
	for (i = 1; i < n; i++) {
		max = 0;
		for (j = 0; j < i; j++) {
			if (arr[i] < arr[j] && max < dp[j]) // 감소 여부 && 가장 큰 부분순열 여부
				max = dp[j];
		}
		dp[i] = max + arr[i];
	}

	ans = dp[0];
	for (i = 1; i < n; i++)
		if (ans < dp[i])
			ans = dp[i];
	
	cout << ans;
}