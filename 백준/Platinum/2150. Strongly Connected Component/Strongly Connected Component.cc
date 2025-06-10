#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> visit;

Graph G;
Graph GT;
stack<int> finish_stack;
unordered_map<int, set<int>> SCC;

void Phase1(int V) {
	if (visit[V]) return;

	visit[V] = true;

	if (G[V].size()) {
		for (int v : G[V]) {
			if (!visit[v]) {
				Phase1(v);
			}
		}
	}

	finish_stack.push(V);
}

void Phase2(int V, int root) {
	if (visit[V]) return;

	visit[V] = true;

	if (GT[V].size()) {
		for (int v : GT[V]) {
			if (!visit[v]) {
				SCC[root].insert(v);
				Phase2(v, root);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int V, E; cin >> V >> E;

	G.resize(V + 1);
	GT.resize(V + 1);

	while (E--) {
		int A, B; cin >> A >> B;
		G[A].push_back(B);
		GT[B].push_back(A);
	}

	visit.clear();
	visit.resize(V + 1, false);
	for (int i = 1; i <= V; i++) {
		Phase1(i);
	}

	visit.clear();
	visit.resize(V + 1, false);
	while (!finish_stack.empty()) {
		int root = finish_stack.top();
		if (!visit[root]) {
			SCC[root].insert(root);
			Phase2(root, root);
		}

		finish_stack.pop();
	}

	set<pair<int, int>> order;
	for (auto a : SCC) {
		order.insert({ *(a.second.begin()), a.first});
	}

	cout << SCC.size() << '\n';
	for (pair<int, int> root : order) {
		for (int i : SCC[root.second]) {
			cout << i << ' ';
		}
		cout << "-1\n";
	}
}