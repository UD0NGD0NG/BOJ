#include <iostream>
#include <vector>
#include <queue> // priority_queue
#include <algorithm> // min
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<pair<int, int>> pq;
	int V, E, K, u, v, w, i; // 문제와 동일
	cin >> V >> E >> K;
	vector<int> dist(V + 1, 210000); dist[K] = 0; // 시작점의 거리는 0, 나머지는 최대치(INT_MAX사용시 오버플로우 주의)
	vector<vector<pair<int, int>>> edge(V + 1); // 그래프의 간선정보 저장

	while (E--) {
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(w, v));
	}

	for (i = 1; i <= V; i++) pq.push(make_pair(-dist[i], i)); // 거리가 최소인 값을 우선시 하므로 -붙여서 push

	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push(make_pair(-dist[y.second], y.second)); // 짧은 거리가 생겼다면 push
			}
		}
	}

	for (i = 1; i <= V; i++) {
		if (dist[i] == 210000) cout << "INF\n"; // 거리가 변하지 않았다면 도달할 수 없는 정점이므로 INF출력
		else cout << dist[i] << '\n';
	}
}