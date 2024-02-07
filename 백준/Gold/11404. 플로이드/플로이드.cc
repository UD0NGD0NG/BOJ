#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, a, b, c; // same with problem
	int INF = 10000000, i, j, k; // limit, index
	cin >> n >> m;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	vector<vector<pair<int, int>>> edge(n + 1);

	while (m--) { // build graph
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
	}

	for (i = 1; i <= n; i++) {
		dist[i][i] = 0; // self -> self == 0
		for (pair<int, int> x : edge[i]) {
			dist[i][x.first] = min(dist[i][x.first], x.second); // smallest distance
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]); // j -> k  vs  j -> i -> k
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (dist[i][j] != INF) cout << dist[i][j] << ' ';
			else cout << "0 ";
		}
		cout << '\n';
	}
}