#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> X = { 0, 1, 0, -1 }, Y = { 1, 0, -1, 0 }; // dx/dy

int r, c, ans = 0;
vector<vector<char>> board(22, vector<char>(22));
vector<pair<int, int>> Move = { make_pair(1, 1) }; // 시작 위치를 첫번째 다음 위치로 초기화
map<char, int> mp; // second가 0이면 미방문, second가 1이면 방문

void backtracking() {
	for (int i = 0; i < 4; i++) {
		char next = board[Move.back().first + X[i]][Move.back().second + Y[i]]; // 나아갈 위치의 문자값 저장
		if (next && !mp[next]) { // 문자가 공백이 아니거나(범위 밖) 방문하지 않은 경우
			Move.push_back(make_pair(Move.back().first + X[i], Move.back().second + Y[i])); // 다음 위치로 지정
			mp[next]++; // 해당 문자 방문처리
			backtracking(); // backtracking
			Move.pop_back();
			mp[next]--;
		}
	}
	ans = max(ans, int(Move.size())); // 현재 스코프에서 모두 탐색했다면(더이상 나아갈 수 있는 위치가 없다면 최댓값인지 판정)
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
		}
	}

	mp[board[1][1]] = 1; // 시작 지점의 알파벳 방문처리

	backtracking();

	cout << ans;
}