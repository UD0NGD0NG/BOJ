#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 8101;

	int n; cin >> n;
	vector<string> form(n + 1); for (int i = 1; i <= n; i++) cin >> form[i];

	vector<vector<pair<ll, int>>> edge(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ll cost = 0;
			for (int k = 0; k < form[i].size(); k++) {
				cost += (form[i][k] - form[j][k]) * (form[i][k] - form[j][k]);
			}

			edge[i].push_back(make_pair(cost, j));
		}
	}

	int start, end; cin >> start >> end;
	vector<int> dist(n + 1, INF); dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
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

	cout << dist[end];
}