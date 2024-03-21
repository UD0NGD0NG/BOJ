#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<int> X{ 0,1,0,-1 }, Y{ 1,0,-1,0 };
	int n;  cin >> n;
	
	int cnt1 = 0, cnt2 = 0; // 적록색약X의 구역수, 적록색약O의 구역수
	vector<vector<char>> v(n + 2, vector<char>(n + 2, 'X')); // 그리드(탐색하면 안되는 공간구별을 위하여 X로 초기화)
	vector<vector<bool>> visit1(n + 2, vector<bool>(n + 2, false)); // 적록색약X용
	vector<vector<bool>> visit2(n + 2, vector<bool>(n + 2, false)); // 적록색약O용
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	queue<pair<int, int>> q; // bfs
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit1[i][j]) { // 아직 방문하지 않은 정점(구역의 시작점)을 만나면
				cnt1++; // 구역의 개수 증가
				q.push(make_pair(i, j)); // 해당 정점에 대하여

				while (!q.empty()) {
					pair<int, int> x = q.front();
					q.pop();

					for (int idx = 0; idx < 4; idx++) { // 상하좌우를 비교하며
						if (!visit1[x.first + X[idx]][x.second + Y[idx]] && v[x.first + X[idx]][x.second + Y[idx]] == v[x.first][x.second]) { // 아직방문하지 않았으며 해당 정점과 같은 색상의 정점에 대하여
							visit1[x.first + X[idx]][x.second + Y[idx]] = true; // 방문처리(같은 구역임을 표시)
							q.push(make_pair(x.first + X[idx], x.second + Y[idx])); // 모든 인접한 구역 처리를 위함
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) { // 적록색약이라면
		for (int j = 1; j <= n; j++) {
			if (!visit2[i][j]) {
				cnt2++;
				q.push(make_pair(i, j));

				while (!q.empty()) {
					pair<int, int> x = q.front();
					q.pop();

					if (v[x.first][x.second] == 'B') { // 파란색의 경우 파란색끼리만 같은구역
						for (int idx = 0; idx < 4; idx++) {
							if (!visit2[x.first + X[idx]][x.second + Y[idx]] && v[x.first + X[idx]][x.second + Y[idx]] == 'B') {
								visit2[x.first + X[idx]][x.second + Y[idx]] = true;
								q.push(make_pair(x.first + X[idx], x.second + Y[idx]));
							}
						}
					}
					else {
						for (int idx = 0; idx < 4; idx++) { // 초록색과 빨간색은 서로 같은구역
							if (!visit2[x.first + X[idx]][x.second + Y[idx]] && (v[x.first + X[idx]][x.second + Y[idx]] == 'G' || v[x.first + X[idx]][x.second + Y[idx]] == 'R')) {
								visit2[x.first + X[idx]][x.second + Y[idx]] = true;
								q.push(make_pair(x.first + X[idx], x.second + Y[idx]));
							}
						}
					}
				}
			}
		}
	}

	cout << cnt1 << ' ' << cnt2;
}