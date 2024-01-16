#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q;
	vector<int> I = { -1,-1,-1,0,0,1,1 }, J = { -1,0,1,-1,1,-1,1 }; // 탐색 가능구역 (도착지에서부터 탐색을 하기에 W키가 빠졌지만 X키 방향을 없앰)
	int n, i, j, idx, cnt = 0;
	string s;
	cin >> n;
	vector<vector<char>> v(n + 2, vector<char>(n + 2, '#')); // 게임판을 저장하는 vector(가장 바깥 줄은 도달할 수 없으므로 #으로 초기화)
	vector<vector<bool>> visit(n + 2, vector<bool>(n + 2, false)); // 방문여부를 저장하는 vector
	for (i = 1; i <= n; i++) {
		cin >> s;
		for (j = 1; j <= n; j++) {
			v[i][j] = s[j - 1];
			if (v[i][j] == 'F') { // 도착지를 큐에 삽입 && 방문처리
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		for (idx = 0; idx < 7; idx++) {
			if (v[x.first + I[idx]][x.second + J[idx]] != '#' && !visit[x.first + I[idx]][x.second + J[idx]]) { // 탐색 가능구역 중 아직 방문하지 않았다면
				q.push(make_pair(x.first + I[idx], x.second + J[idx])); // 해당 구역 큐에 삽입
				visit[x.first + I[idx]][x.second + J[idx]] = true; // 해당 구역 방문처리
				cnt++; // 가능한 시작점의 수 +1
			}
		}
	}
	cout << cnt;
}
