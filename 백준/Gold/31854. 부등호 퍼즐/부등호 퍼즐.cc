#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> ans(n * n + 1);

	vector<vector<int>> edge(n * n + 1); // 좌상단 칸의 index를 1, 우하단 칸의 index를 n*n으로 설정
	vector<int> degree(n * n + 1, 0); // 진입차수 저장

	// 가로로 인접한 격자판
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			int a = n * (i - 1) + j;
			int b = a + 1;
			// 부등호가 벌어진쪽은 반대편보다 더 큰 숫자가 들어가야하므로 진입차수를 높여줌(후순위로 배정)
			char c; cin >> c;
			if (c == '<') {
				edge[a].push_back(b);
				degree[b]++;
			}
			else {
				edge[b].push_back(a);
				degree[a]++;
			}
		}
	}

	// 세로로 인접한 격자판
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			int a = n * (i - 1) + j;
			int b = a + n;
			// 부등호가 벌어진쪽은 반대편보다 더 큰 숫자가 들어가야하므로 진입차수를 높여줌(후순위로 배정)
			char c; cin >> c;
			if (c == '<') {
				edge[a].push_back(b);
				degree[b]++;
			}
			else {
				edge[b].push_back(a);
				degree[a]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= n * n; i++) {
		if (!degree[i]) q.push(i);
	}

	int curNum = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		ans[x] = curNum++; // 진입차수가 없는 노드부터 숫자 배정

		for (int y : edge[x]) {
			degree[y]--;
			if (!degree[y]) q.push(y);
		}
	}

	for (int i = 1; i <= n * n; i++) {
		cout << ans[i] << ' ';
		if (i % n == 0) cout << '\n';
	}
}