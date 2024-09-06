#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 50'000'001;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> edge(n + 1);

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	int p, q; cin >> p >> q;

	set<int> home;
	while (p--) {
		int idx; cin >> idx;
		home.insert(idx);
	}

	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;
	while (q--) {
		int idx; cin >> idx;
		pq.push({ 0, idx });
		dist[idx] = 0;
	}

	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dist[y.second] != min(dist[y.second], dist[x] + y.first)) {
				dist[y.second] = min(dist[y.second], dist[x] + y.first);
				pq.push({ -dist[y.second], y.second });
			}
		}
	}

	pair<int, int> ans = { INF, n + 1 };
	for (int x : home) {
		if (dist[x] != INF && dist[x] < ans.first) { // 가장 낮은 정점 번호로 갱신
			ans = { dist[x], x };
		}
	}

	cout << ans.second;
}