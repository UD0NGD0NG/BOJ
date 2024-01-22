#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> q;
	int n, m, k, x, a, b, idx, flag = 1;
	cin >> n >> m >> k >> x;
	vector<vector<int>> edge(n + 1);
	vector<int> dist(n + 1, -1); // 아직 방문하지 않은 node까지의 거리는 -1
	dist[x] = 0; // 시작 node까지의 거리는 0
	q.push(x);
	while (m--) {
		cin >> a >> b;
		edge[a].push_back(b); // 단방향 그래프
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		for (int j : edge[i]) {
			if (dist[j] == -1) { // 방문 여부 확인
				dist[j] = dist[i] + 1; // 새로 방문한 node까지의 거리는 이전에 방문한 node까지의 거리 +1
				q.push(j);
			}
		}
	}
	for (idx = 1; idx <= n; idx++) {
		if (dist[idx] == k) {
			cout << idx << '\n';
			flag = 0; // 최단 거리가 k인 도시가 있는경우 flag값을 0(false)로 변경
		}
	}
	if (flag) // 최단 거리가 k인 도시가 없는 경우
		cout << -1;
}