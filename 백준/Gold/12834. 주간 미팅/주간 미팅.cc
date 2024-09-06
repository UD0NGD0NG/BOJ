#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 1000001;
	int n, v, e; cin >> n >> v >> e;
	int a, b; cin >> a >> b;

	vector<int> h(n + 1); for (int i = 1; i <= n; i++) cin >> h[i];
	vector<vector<pair<int, int>>> edge(v + 1);

	while (e--) {
		int a, b, l; cin >> a >> b >> l;
		edge[a].push_back(make_pair(l, b));
		edge[b].push_back(make_pair(l, a));
	}

	int total = 0;
	for (int i = 1; i <= n; i++) { // 모든 사람을 한번씩 판단
		int startIdx = h[i];
		vector<int> dist(v + 1, INF); dist[startIdx] = 0;

		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, startIdx));
		while (!pq.empty()) {
			int x = pq.top().second;
			pq.pop();
			for (pair<int, int> y : edge[x]) {
				if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
					dist[y.second] = min(dist[y.second], dist[x] + y.first);
					pq.push(make_pair(-dist[y.second], y.second)); // 거리가 최솟값으로 갱신되었다면 push(다익스트라)
				}
			}
		}
		// KIST 도달 여부
		if (dist[a] == INF)	total += -1;
		else total += dist[a];
		// 씨알푸드 도달 여부
		if (dist[b] == INF) total += -1;
		else total += dist[b];
	}

	cout << total;
}