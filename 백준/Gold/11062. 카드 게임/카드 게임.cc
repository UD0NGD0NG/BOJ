#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, sum = 0; cin >> N;
		vector<int> card(N);
		for (int i = 0; i < N; i++) {
			cin >> card[i];
			sum += card[i];
		}

		vector<vector<int>> dp(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) dp[i][i] = card[i];

		for (int len = 1; len < N; len++) {
			for (int l = 0; l + len < N; l++) {
				int r = l + len;
				dp[l][r] = max(card[l] - dp[l + 1][r], card[r] - dp[l][r - 1]);
			}
		}

		cout << (sum + dp[0][N - 1]) / 2 << '\n';
	}
}