#include <iostream>
#include <vector>
using namespace std;
using tree = vector<vector<int>>;

tree T;
vector<bool> visit;
vector<int> descendantCount;

void DFS(int curNode, int count) {
	visit[curNode] = true;

	int cur_count = count;
	for (int nextNode : T[curNode]) {
		if (!visit[nextNode]) {
			DFS(nextNode, 1);
			cur_count += descendantCount[nextNode];
		}
	}

	descendantCount[curNode] = cur_count;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, r, q; cin >> n >> r >> q;
	
	T.resize(n + 1); visit.resize(n + 1); descendantCount.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	DFS(r, 1);

	for (int i = 0; i < q; i++) {
		int u; cin >> u;
		cout << descendantCount[u] << '\n';
	}
}