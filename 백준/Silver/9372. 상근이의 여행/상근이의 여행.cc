#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>& uf, int node) {
	if (uf[node] == node) return node;

	int root = Find(uf, uf[node]);
	uf[node] = root;
	return root;
}

void Union(vector<int>& uf, int node1, int node2) {
	int root1 = Find(uf, node1), root2 = Find(uf, node2);

	uf[root1] = root2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;

		vector<int> uf(n + 1); for (int i = 1; i <= n; i++) uf[i] = i;
		vector<vector<int>> plane(n + 1);

		int cnt = 0; // 선택한 비핼기 수
		while (m--) {
			int a, b; cin >> a >> b;
			if (Find(uf, a) != Find(uf, b)) { // 두 도시가 이어져있지 않다면
				cnt++; // 해당 비행기 선택
				Union(uf, a, b); // 두 도시 잇기
			}
		}

		cout << cnt << '\n';
	}
}