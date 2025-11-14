/*
1. 트리입력
2. dfs로 depth 계산 및 dp table에 부모(2^0 번째 조상) 저장
3. log 최대깊이 만큼 조상 구해두기(root의 조상은 root로 해놔야 꼬이지 않음)
4. LCA를 구할 2 노드를 입력받은 뒤 함수 호출
	4-1. 함수에서는 두 node의 깊이를 같도록 한쪽을 올림(jump로 빠르게)
	4-2. 깊이를 맞췄을때 같다면 해당 값이 lca
	4-3. 다를경우 최대치부터 점프가 가능한지(점프 이후에도 부모가 다른지)확인 후 점프
	4-4. 점프를 완료한경우 lca의 직전 두 노드인 상황이므로 현 시점에서의 부모 return
*/

#include <iostream>
#include <vector>
using namespace std;

const int lim = 16;
vector<vector<int>> tree, dp;
vector<int> depth;

void dfs(int curNode, int parNode) {
	dp[0][curNode] = parNode;
	for (int next : tree[curNode]) {
		if (next == parNode) continue;
		depth[next] = depth[curNode] + 1;
		dfs(next, curNode);
	}
}

int lca(int n1, int n2) {
	if (depth[n1] < depth[n2]) swap(n1, n2);
	int diff = depth[n1] - depth[n2];

	while (diff) {
		for (int i = lim; i >= 0; i--) {
			if (diff >= 1 << i) {
				n1 = dp[i][n1];
				diff -= 1 << i;
			}
		}
	}

	if (n1 == n2) return n1;

	for (int i = lim; i >= 0; i--) {
		if (dp[i][n1] != dp[i][n2]) {
			n1 = dp[i][n1]; n2 = dp[i][n2];
		}
	}

	return dp[0][n1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	tree.assign(N + 1, {}); depth.assign(N + 1, 1); dp.assign(lim + 1, vector<int>(N + 1, 1));
	for (int i = 1; i < N; i++) {
		int n1, n2; cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	dfs(1, 1);

	for (int i = 1; i <= lim; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

	int M; cin >> M;
	while (M--) {
		int n1, n2; cin >> n1 >> n2;
		cout << lca(n1, n2) << '\n';
	}
}