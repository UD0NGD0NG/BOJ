#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		vector<vector<int>> sticker(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		}

		vector<vector<int>> score(2, vector<int>(n, 0));
		score[0][0] = sticker[0][0], score[1][0] = sticker[1][0]; // 맨 앞은 자기 자신이 최대 점수
		score[0][1] = score[1][0] + sticker[0][1], score[1][1] = score[0][0] + sticker[1][1]; // 2번째 줄은 대각선을 고르는것이 최대 점수

		for (int i = 2; i < n; i++) { // 대각선 고르기 vs 앞줄 건너뛰기
			score[0][i] = max(score[1][i - 2], score[1][i - 1]) + sticker[0][i];
			score[1][i] = max(score[0][i - 2], score[0][i - 1]) + sticker[1][i];
		}

		cout << max(score[0][n - 1], score[1][n - 1]) << '\n'; // 끝까지 판정 후 위와 아래 중 최댓값 고르기
	}
}