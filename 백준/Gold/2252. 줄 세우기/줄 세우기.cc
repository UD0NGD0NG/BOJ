#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<vector<int>> comp(n + 1);
	vector<int> degree(n + 1, 0); // 진입차수 저장

	while (m--) {
		int a, b; cin >> a >> b;

		comp[a].push_back(b);
		degree[b]++; // 앞에 서야하는 학생이 생기면 진입차수++
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			q.push(i); // 진입차수가 없다면(앞에 서도 된다면) 큐에 삽입
		}
	}

	while (!q.empty()) {
		int x = q.front();
		cout << x << ' '; // 진입차수가 없는 경우 바로 출력
		q.pop();

		for (int y : comp[x]) { // 해당 학생의 뒤에 서야하는 학생들의
			degree[y]--; // 진입차수--
			if (!degree[y]) { // 더이상 앞에 서야하는 학생이 없다면
				q.push(y); // 큐에 삽입
			}
		}
	}
}