#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;
using tiii = tuple<int, int, int>;
using vtiii = vector<tiii>;

vpii adj = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

vvi map; // 0 : sea, 1 : land
vvi visit; // 0 : yet, 1 : visited
vpii land;

struct pair_hash {
	size_t operator()(const pair<int, int>& p) const {
		return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
	}
};

unordered_map<pair<int, int>, int, pair_hash> island;

vi uf;
vtiii bridge;

vtiii mst;

int n, m, islandNum;

bool isValid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void composeIsland() {
	for (auto a : land) {
		if (!visit[a.first][a.second]) {
			queue<pii> q; q.push(a); island[a] = ++islandNum;
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				for (pii ij : adj) {
					int i = cur.first + ij.first, j = cur.second + ij.second;
					if (isValid(i, j) && map[i][j] && !visit[i][j]) {
						visit[i][j] = 1;
						island[{i, j}] = islandNum;
						q.push({ i, j });
					}
				}
			}
		}
	}
}

void buildBridge() {
	for (auto a : land) {
		int i = 1, j = 1;
		while (isValid(a.first + i, a.second) && !map[a.first + i][a.second]) {
			i++;
		}
		if (isValid(a.first + i, a.second) && island[a] != island[{a.first + i, a.second}] && i > 2) {
			bridge.push_back(make_tuple(island[a], island[{a.first + i, a.second}], i - 1));
		}

		while (isValid(a.first, a.second + j) && !map[a.first][a.second + j]) {
			j++;
		}
		if (isValid(a.first, a.second + j) && island[a] != island[{a.first, a.second + j}] && j > 2) {
			bridge.push_back(make_tuple(island[a], island[{a.first, a.second + j}], j - 1));
		}
	}
}

bool comp(tiii& t1, tiii& t2) {
	return get<2>(t1) < get<2>(t2);
}

int Find(int node) {
	if (uf[node] == node) return node;

	int root = Find(uf[node]);
	uf[node] = root;
	return root;
}

void Union(int node1, int node2) {
	int root1 = Find(node1), root2 = Find(node2);
	uf[root1] = root2;
}

void MST() {
	for (tiii t : bridge) {
		if (Find(get<0>(t)) != Find(get<1>(t))) {
			mst.push_back(t);
			Union(get<0>(t), get<1>(t));
		}
	}

	int ans = 0;
	for (tiii t : mst) {
		ans += get<2>(t);
	}

	for (int i = 2; i <= islandNum; i++) {
		if (Find(uf[i]) != Find(uf[1])) {
			cout << -1;
			return;
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	map.resize(n, vi(m)); visit.resize(n, vi(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j]) land.push_back({ i, j });
		}
	}

	composeIsland();
	
	bridge.resize(islandNum + 1);
	buildBridge();

	uf.resize(islandNum + 1); for (int i = 1; i <= islandNum; i++) uf[i] = i;
	sort(bridge.begin(), bridge.end(), comp);
	MST();
}