#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>& uf, int node) {
	if (node == uf[node]) return node;

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
	int n, m; cin >> n >> m;

	vector<int> uf(n); for (int i = 0; i < n; i++) uf[i] = i;

	int ans = 0, flag = 1;
	for (int i = 1; i <= m; i++) {
		int node1, node2; cin >> node1 >> node2;
		if (flag) {
			if (Find(uf, node1) != Find(uf, node2)) { // 두 점을 이었을 떄 사이클이 생기지 않음
				Union(uf, node1, node2); // 두 점을 이어줌
			}
			else { // 생긴다면
				ans = i; // 몇번째에 생겼는지 기록
				flag = 0; // 사이클이 생긴경우 이후의 게임결과에 대해 고민하지 않아도 됨
			}
		}
	}

	cout << ans;
}