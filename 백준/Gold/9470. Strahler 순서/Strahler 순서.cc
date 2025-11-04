#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int k, m, p; cin >> k >> m >> p;
		vector<int> degree(m + 1, 0);
		vector<vector<int>> edge(m + 1);
		while (p--) {
			int a, b; cin >> a >> b;
			degree[b]++;
			edge[a].push_back(b);
		}

		vector<int> order(m + 1, 0); queue<int> q;
		for (int i = 1; i <= m; i++) {
			if (!degree[i]) {
				order[i] = 1;
				q.push(i);
			}
		}

		vector<bool> flag(m + 1, false);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : edge[cur]) {
				if (order[cur] > order[next]) flag[next] = false;
				else if (order[cur] == order[next]) flag[next] = true;

				order[next] = max(order[next], order[cur]);

				degree[next]--;

				if (!degree[next]) {
					order[next] += flag[next];
					q.push(next);
				}
			}
		}

		cout << k << ' ' << order[m] << '\n';
	}
}