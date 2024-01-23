#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> I = { -1, 0, 1, 0 }, J = { 0, 1, 0, -1 }; // 상하좌우 순회
	queue<pair<int, int>> q;
	int n, max = 0, i, j, height, idx, cnt, ans = 1;
	cin >> n;
	vector<vector<int>> v(n + 2, vector<int>(n + 2, 0));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> v[i][j];
			if (max < v[i][j])
				max = v[i][j]; // 최대 높이 저장
		}
	}
	for (height = 1; height < max; height++) { // 최대 높이 -1 지역이 잠길때까지 판정
		vector<vector<bool>> visit(n + 2, vector<bool>(n + 2, false));
		cnt = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (v[i][j] > height && !visit[i][j]) {
					q.push(make_pair(i, j));
					visit[i][j] = true;
					cnt++; // 물에 잠기지 않으면서 아직 방문하지 않은 지역을 방문할때 마다 카운트 올려주기
					while (!q.empty()) { // bfs를 통해 인접한 영역 방문처리
						pair<int, int> x = q.front();
						q.pop();
						for (idx = 0; idx < 4; idx++) { // 인접한 영역은 하나의 안전한 영역으로 판단하므로 카운트 변화 X
							if (v[x.first + I[idx]][x.second + J[idx]] > height && !visit[x.first + I[idx]][x.second + J[idx]]) {
								visit[x.first + I[idx]][x.second + J[idx]] = true;
								q.push(make_pair(x.first + I[idx], x.second + J[idx]));
							}
						}
					}
				}
			}
		}
		if (ans < cnt) // 안전한 영역의 수가 최대가 되도록 판정
			ans = cnt;
	}
	cout << ans;
}