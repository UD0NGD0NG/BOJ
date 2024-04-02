#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<vector<int>> order(n + 1); // 먼저 풀어야하는 정보 저장
	vector<int> degree(n + 1, 0); // 먼저풀어야하는 문제의 개수 저장

	while (m--) {
		int a, b; cin >> a >> b;
		degree[b]++;
		order[a].push_back(b);
	}

	priority_queue<int> pq; // 우선순위 큐를 사용하여 난이도가 낮은문제가 큐의 맨앞에 저장되도록 유지
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			pq.push(-i); // 작은 수가 top에 있어야하므로 음수처리를 하여 큐에 삽입
		}
	}

	while (!pq.empty()) {
		int x = -pq.top(); // 음수값을 큐에 넣었으므로 값을 가져올때도 음수처리
		pq.pop();
		cout << x << ' ';

		for (int y : order[x]) {
			degree[y]--;

			if (!degree[y]) {
				pq.push(-y);
			}
		}
	}
}