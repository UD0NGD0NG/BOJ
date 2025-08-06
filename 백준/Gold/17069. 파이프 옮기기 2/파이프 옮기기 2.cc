#include <iostream>
#include <vector>
using namespace std;
using v = vector<long long>;
using vv = vector<v>;
using vvv = vector<vv>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vv house(N, v(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}

	vvv dp(4, vv(N, v(N, 0))); // head, row, col
	dp[1][0][1] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!house[i][j]) {
				if (j) {
					dp[1][i][j] += dp[1][i][j - 1] + dp[3][i][j - 1];
				}
				if (i) {
					dp[2][i][j] += dp[2][i - 1][j] + dp[3][i - 1][j];
				}
				if (i && j && !house[i - 1][j] && !house[i][j - 1]) {
					dp[3][i][j] += dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1] + dp[3][i - 1][j - 1];
				}
			}
		}
	}

	cout << dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1] + dp[3][N - 1][N - 1];
}