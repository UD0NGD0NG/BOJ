#include <iostream>
#include <vector>
using namespace std;

int sum = 0;
vector<vector<int>> edge;
vector<int> depth;
vector<bool> visit;

void DFS(int cur) {
	visit[cur] = true;

	bool leaf = true;
	for (int next : edge[cur]) {
		if (!visit[next]) {
			depth[next] = depth[cur] + 1;
			DFS(next);
			leaf = false;
		}
	}

	if (leaf) {
		sum += depth[cur];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	edge.resize(n + 1);
	depth.resize(n + 1);
	visit.resize(n + 1);
	
	n--;
	while (n--) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	DFS(1);

	sum % 2 ? cout << "Yes" : cout << "No";
}