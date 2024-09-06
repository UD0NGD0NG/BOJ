#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, r; cin >> n >> m >> r;

	vector<int> item(n + 1); for (int i = 1; i <= n; i++) cin >> item[i];
	vector<vector<pair<int, int>>> edge(n + 1);

	while (r--) {
		int a, b, l; cin >> a >> b >> l;
		edge[a].push_back(make_pair(l, b));
		edge[b].push_back(make_pair(l, a));
	}

	int maxCnt = 0;
	for (int i = 1; i <= n; i++) { // 떨어지는 위치를 모두 탐색
		priority_queue<pair<int, int>> pq;
		vector<int> dist(n + 1, 1501); dist[i] = 0;
		pq.push(make_pair(0, i));
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

		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m) cnt += item[j];
		}

		maxCnt = max(maxCnt, cnt);
	}

	cout << maxCnt;
}