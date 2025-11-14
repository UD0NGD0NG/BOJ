#include <iostream>
#include <vector>
using namespace std;

const int LOG = 17;
vector<vector<int>> parent;
vector<int> depth;
vector<vector<int>> adj;

void dfs(int v, int p) {
	parent[0][v] = p;
	for (int nxt : adj[v]) {
		if (nxt == p) continue;
		depth[nxt] = depth[v] + 1;
		dfs(nxt, v);
	}
}

int lca(int a, int b) {
	// 1) 깊이를 맞춘다
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];

	// 깊이 차이를 2^k 점프로 줄이기
	for (int k = 0; k <= LOG; k++) {
		if (diff & (1 << k)) {
			a = parent[k][a];
		}
	}

	// 이미 같다면 LCA
	if (a == b) return a;

	// 2) 가장 위 레벨부터 내려오며
	// parent[k][a] != parent[k][b] 인 곳을 찾아 둘 다 점프
	for (int k = LOG; k >= 0; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	// 3) 마지막으로 한 칸 위가 LCA
	return parent[0][a];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	adj.assign(N + 1, {}); parent.assign(LOG + 1, vector<int>(N + 1)); depth.assign(N + 1, 0);

	for (int child = 2; child <= N; child++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	depth[1] = 1;
	dfs(1, 1);

	for (int k = 1; k <= LOG; k++) {
		for (int v = 1; v <= N; v++) {
			parent[k][v] = parent[k - 1][parent[k - 1][v]];
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}