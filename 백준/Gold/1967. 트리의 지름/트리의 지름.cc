#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> edge;

void dfs(int node, vector<int>& dist) {
	for (auto a : edge[node]) {
		if (dist[a.first] == -1) {
			dist[a.first] = dist[node] + a.second;

			dfs(a.first, dist);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	edge.resize(n + 1);
	vector<bool> leaf(n + 1, true);
	
	for (int i = 1; i < n; i++) {
		int p, c, w; cin >> p >> c >> w;
		edge[p].push_back({ c, w });
		edge[c].push_back({ p, w });
		
		leaf[p] = false;
	}

	int ans = 0;
	for (int cur = 1; cur <= n; cur++) {
		if (leaf[cur]) {
			vector<int> dist(n + 1, -1); dist[cur] = 0;
			dfs(cur, dist);
			
			int candidate = 0;
			for (int node = 1; node <= n; node++) {
				candidate = candidate > dist[node] ? candidate : dist[node];
			}

			ans = ans > candidate ? ans : candidate;
		}
	}

	cout << ans;
}