#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 100'000'000;
	int v, e, p; cin >> v >> e >> p;
	vector<vector<pair<int, int>>> edge(v + 1);

	while (e--) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back(make_pair(c, b));
		edge[b].push_back(make_pair(c, a));
	}

	vector<int> dist(v + 1, INF); dist[1] = 0;
	// 시작점(1)에서부터 각각의 정점까지의 최단거리 계산
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push(make_pair(-dist[y.second], y.second));
			}
		}
	}

	int minDist = dist[v], gwDist = dist[p]; // midDist: 출발지로부터 마산까지의 최단거리, gwDist: 출발지로부터 건우 위치까지의 최단거리

	if (gwDist == INF) { // 건우를 구할 수 없는 경우
		cout << "GOOD BYE";
		return 0;
	}

	for (int i = 1; i <= v; i++) dist[i] = INF; dist[p] = 0;
	// 건우의 위치(p)에서부터 각각의 정점까지의 최단거리 계산
	pq.push(make_pair(0, p));
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push(make_pair(-dist[y.second], y.second));
			}
		}
	}
	gwDist += dist[v]; // 건우의 위치로부터 마산까지의 최단거리

	if (minDist == gwDist) cout << "SAVE HIM"; // 건우를 구할 수 있으며 최단경로인 경우
	else cout << "GOOD BYE"; // 건우를 구할 수 있으나 최단경로가 아닌 경우
}