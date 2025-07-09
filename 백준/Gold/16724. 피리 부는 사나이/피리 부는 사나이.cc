#include <iostream>
#include <vector>
#include <set>
using namespace std;
using Graph = vector<vector<int>>;

int n, m;
Graph G;

vector<int> UF;

int transformation(int i, int j) {
	return i * m + j + 1;
}

int translate(char c, int i, int j) {
	if (c == 'U') {
		return transformation(i - 1, j);
	}
	else if (c == 'D') {
		return transformation(i + 1, j);
	}
	else if (c == 'L') {
		return transformation(i, j - 1);
	}
	else {
		return transformation(i, j + 1);
	}
}

int Find(int v) {
	if (UF[v] == v) return v;
	return UF[v] = Find(UF[v]);
}

void Union(int u, int v) {
	u = Find(u);
	v = Find(v);

	UF[v] = u;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	G.resize(n * m + 1);
	UF.resize(n * m + 1); for (int i = 1; i <= n * m; i++) UF[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cur = transformation(i, j);
			char c; cin >> c;
			int next = translate(c, i, j);

			G[cur].push_back(next);
		}
	}

	for (int i = 1; i <= n * m; i++) {
		for (int j : G[i]) {
			Union(i, j);
		}
	}

	set<int> ans;
	for (int i = 1; i <= n * m; i++) {
		ans.insert(Find(UF[i]));
	}

	cout << ans.size();
}