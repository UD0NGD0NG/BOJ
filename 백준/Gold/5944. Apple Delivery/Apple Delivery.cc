#include <iostream>
#include <vector>
#include <queue> // priority_queue
#include <algorithm> // min
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 2'000'000'001;

	// 간선의 개수, 정점의 개수, 시작점, 거점1, 거점2
	int c, p, pb, pa1, pa2; cin >> c >> p >> pb >> pa1 >> pa2;
	
	vector<vector<pair<int, int>>> edge(p + 1);
	while (c--) { // make graph
		int p1, p2, d; cin >> p1 >> p2 >> d;
		edge[p1].push_back(make_pair(d, p2));
		edge[p2].push_back(make_pair(d, p1));
	}

	ll route1 = 0, route2 = 0;

	vector<int> dist(p + 1, INF); dist[pb] = 0; // 시작점의 거리는 0, 나머지는 최대치
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, pb));
	while (!pq.empty()) {
		int x = pq.top().second; // current index
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push(make_pair(-dist[y.second], y.second)); // 거리가 최솟값으로 갱신되었다면 push
			}
		}
	}
	route1 += dist[pa1], route2 += dist[pa2];
	
	dist.clear(); dist.resize(p + 1); for (int i = 0; i < dist.size(); i++) dist[i] = INF;
	dist[pa1] = 0; // 시작점의 거리는 0, 나머지는 최대치
	//priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, pa1));
	while (!pq.empty()) {
		int x = pq.top().second; // current index
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push(make_pair(-dist[y.second], y.second)); // 거리가 최솟값으로 갱신되었다면 push
			}
		}
	}
	route1 += dist[pa2];
	
	dist.clear(); dist.resize(p + 1); for (int i = 0; i < dist.size(); i++) dist[i] = INF;
	dist[pa2] = 0; // 시작점의 거리는 0, 나머지는 최대치
	//priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, pa2));
	while (!pq.empty()) {
		int x = pq.top().second; // current index
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push(make_pair(-dist[y.second], y.second)); // 거리가 최솟값으로 갱신되었다면 push
			}
		}
	}
	route2 += dist[pa1];

	cout << min(route1, route2);
}