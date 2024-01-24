#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> q;
	int n, i, j, g;
	cin >> n;
	vector<vector<int>> edge(n);
	vector<vector<int>> can(n, vector<int>(n, 0)); // 방문 가능여부 저장
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> g;
			if (g) // 1이 입력될 경우에만
				edge[i].push_back(j); // 단방향 그래프
		}
	}
	for (i = 0; i < n; i++) { // 모든 정점에서 한번씩 출발
		q.push(i); // 출발 정점이 미방문 상태에서 시작
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : edge[x]) { // 간선이 존재할 때
				if (!can[i][y]) { // 아직 방문하지 않았다면
					can[i][y] = 1; // 방문 가능여부를 가능으로 변경
					q.push(y);
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << can[i][j] << ' ';
		cout << '\n';
	}
}