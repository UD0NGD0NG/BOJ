#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using qpii = queue<pii>;

int n, m;
vi X{ 0, 1, 0, -1 }, Y{ 1, 0, -1, 0 };

bool valid(int x, int y) {
	return 0 < x && x <= n && 0 < y && y <= m;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 199'801;
	int r, c; cin >> n >> m >> r >> c;

	// 0: empty || conveni, 1: room
	vvi map(n + 1, vi(m + 1, 0));

	vvi fee(n + 1, vi(m + 1));
	for (int i = 0; i < r; i++) {
		int a, b, p; cin >> a >> b >> p;

		fee[a][b] = p;
		map[a][b] = 1;
	}

	qpii q;
	vvi dist(n + 1, vi(m + 1, -1));

	for (int i = 0; i < c; i++) {
		int a, b; cin >> a >> b;
		q.push({ a, b }); // q에 편의점의 좌표를 다 떄려넣음(bfs시작점)
		dist[a][b] = 0;
	}



	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int idx = 0; idx < 4; idx++) {
			int curX = x + X[idx], curY = y + Y[idx];
			if (valid(curX, curY)) {
				if (dist[curX][curY] == -1 || dist[curX][curY] > dist[x][y] + 1) { // 아직 방문하지 않은 곳이거나 현재 방문이 도달가능한 최단거리일 경우 방문처리
					q.push({ curX, curY });
					dist[curX][curY] = dist[x][y] + 1;
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) { // 집인 경우
				ans = min(ans, dist[i][j] * fee[i][j]); // 편의점까지의 거리와 현재 집의 월세의 곱이 최솟값인지 확인
			}
		}
	}

	cout << ans;
}