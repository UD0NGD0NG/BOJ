#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int DP[1001] = {}; // 문제에서 주어진 조건중 최댓값으로 배열 선언
	DP[0] = 1, DP[1] = 1;
	int n, i, mod = 10007;
	cin >> n;
	for (i = 2; i <= n; i++)
		DP[i] = ((DP[i - 1] % mod) + (DP[i - 2] * 2) % mod) % mod; // 점화식: DP[n] = DP[n - 1] + DP[n - 2] * 2
	cout << DP[n];
}