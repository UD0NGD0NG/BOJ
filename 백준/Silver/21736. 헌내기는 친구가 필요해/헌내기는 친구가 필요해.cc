#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q; // bfs를 위한 queue
	vector<int> I = { -1, 0, 1, 0 }, J = { 0, 1, 0, -1 }; // 이동 방법(상 하 좌 우)
	int n, m, p = 0, i, j, idx; // p는 만난 사람의 수, 나머지는 index관리용 변수
	string s; // 캠퍼스 정보를 줄단위로 입력받기 위한 변수
	cin >> n >> m;
	vector<vector<char>> v(n + 2, vector<char>(m + 2, 'X')); // 겉에 한줄을 추가하여 벽으로 추가하여 범위체크 단순화
	vector<vector<bool>> visit(n + 2, vector<bool>(m + 2, false));
	for (i = 1; i <= n; i++) {
		cin >> s;
		for (j = 1; j <= m; j++) {
			v[i][j] = s[j - 1]; // 줄로 입력받은 캠퍼스 정보를 글자 단위로 변환
			if (v[i][j] == 'I') { // 도연이의 위치(탐색 시작 위치) 저장
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		for (idx = 0; idx < 4; idx++) {
			if (v[x.first + I[idx]][x.second + J[idx]] != 'X' && !visit[x.first + I[idx]][x.second + J[idx]]) {
				if (v[x.first + I[idx]][x.second + J[idx]] == 'P') // P를 만나면 p(만난 사람의 수) 값 올려주기
					p++;
				q.push(make_pair(x.first + I[idx], x.second + J[idx]));
				visit[x.first + I[idx]][x.second + J[idx]] = true;
			}
		}
	}
	if (p) // p != 0
		cout << p;
	else // p == 0
		cout << "TT";
}