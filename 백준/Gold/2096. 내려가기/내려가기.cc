#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, i, j;
	cin >> n;
	char arr[100000][3] = {}; // 문제의 제한조건안에 들어가기 위해 char타입 배열 선언
	int dp[100000][3] = {};
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			cin >> arr[i][j];
	for (i = 0; i < 3; i++)
		dp[0][i] = arr[0][i] - '0'; // char타입으로 입력을 받았기에 실제 최대/최솟값을 저장하는 배열에는 정수값으로 변환
	for (i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][0] - '0';
		dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + arr[i][1] - '0';
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][2] - '0';
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << ' ';
	for (i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0] - '0';
		dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + arr[i][1] - '0';
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][2] - '0';
	}
	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}