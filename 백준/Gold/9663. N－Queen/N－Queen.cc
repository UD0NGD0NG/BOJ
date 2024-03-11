#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
vector<pair<int, int>> chess;

void backtracking() {
	if (chess.size() == n) {
		cnt++;
		return;
	}

	int i = chess.size();
	for (int j = 0; j < n; j++) {
		bool flag = true; // 이미 자리가 정해진 퀸들에게 공격을 받는지 여부

		for (int k = 0; k < i; k++) {
			if (abs(chess[k].first - i) == abs(chess[k].second - j) || chess[k].second == j) { // 같은 대각선에 있나 같은 열에 있다면
				flag = false; // 공격을 받음
				break;
			}
		}

		if (flag) { // 공격을 받지 않는다면
			chess.push_back(make_pair(i, j)); // 자리 확정
			backtracking(); // n개의 자리가 확정될때까지 재귀
			chess.pop_back(); // 현재 행 중 다른 열에 퀸을 놓는경우 탐색
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	backtracking();

	cout << cnt;
}