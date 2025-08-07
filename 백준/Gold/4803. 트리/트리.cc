#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using vi = vector<int>;
using Graph = vector<vi>;

int Find(vi& uf, int v) {
	if (uf[v] == v) return v;
	return uf[v] = Find(uf, uf[v]);
}

void Union(vi& uf, int u, int v) {
	u = Find(uf, u);
	v = Find(uf, v);

	uf[v] = u;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c = 1;
	int n, m; cin >> n >> m;
	while (n + m) {
		vi UF(n + 1); for (int i = 1; i <= n; i++) UF[i] = i;
		Graph g(n + 1);
		while (m--) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			for (int j : g[i]) {
				Union(UF, i, j);
			}
		}
		
		unordered_map<int, set<int>> mp;
		for (int i = 1; i <= n; i++) {
			mp[Find(UF, i)].insert(i);
		}
		int T = mp.size();

		for (pair<int, set<int>> a : mp) {
			vi uf(n + 1); for (int i = 1; i <= n; i++) uf[i] = i;
			
			bool flag = false;
			for (int b : a.second) {
				for (int c : g[b]) {
					if (Find(uf, b) != Find(uf, c)) Union(uf, b, c);
					else {
						flag = true; T--; break;
					}
				}
				if (flag) break;
			}
		}

		cout << "Case " << c++ << ": ";
		if (!T) {
			cout << "No trees.\n";
		}
		else if (T == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << T << " trees.\n";
		}

		cin >> n >> m;
	}
}