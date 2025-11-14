#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int N; cin >> N;
	vector<vector<int>> tree(N + 1);
	vector<int> parent(N + 1, 1), depth(N + 1, 0); depth[1] = 1;
	for (int i = 2; i <= N; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	queue<int> q; q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : tree[cur]) {
			if (!depth[next]) {
				q.push(next);
				depth[next] = depth[cur] + 1;
				parent[next] = cur;
			}
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int a, b; cin >> a >> b;
		while (a != b) {
			if (depth[a] < depth[b]) {
				b = parent[b];
			}
			else {
				a = parent[a];
			}
		}

		cout << a << '\n';
	}
}