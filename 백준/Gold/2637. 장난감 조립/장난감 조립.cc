#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	int indegree[105]{}, outdegree[105]{}, edge[105][105]{}, cnt[105][105]{};
	while (m--) {
		int x, y, k; cin >> x >> y >> k;
		cnt[x][y] = k;
		indegree[y]++;
		outdegree[x]++;
		edge[x][y] = 1;
	}

	unordered_map<int, int> ans[105];
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
			ans[i][1]++;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next = 1; next < n; next++) {
			if (edge[cur][next]) {
				for (auto a : ans[cur]) {
					ans[next][a.first * cnt[cur][next]] += a.second;
				}
				
				indegree[next]--;

				if (!indegree[next]) {
					q.push(next);
				}
			}
		}
	}

	int basic[105]{};
	for (int i = 1; i < n; i++) {
		if (!outdegree[i]) {
			int sum = 0;
			for (auto a : ans[i]) {
				sum += a.first * a.second;
			}

			cout << i << ' ' << sum << '\n';
		}
	}
}