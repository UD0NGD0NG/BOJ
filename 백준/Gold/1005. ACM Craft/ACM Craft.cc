#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; // testcase 수

	while (t--) {
		//bool flag = true; // w의 진입차수가 있다면 true, 0이면 false
		int n, k; cin >> n >> k; // 건물 수, 규칙 수

		// 모든 vector는 1-based
		vector<int> degree(n + 1, 0); // 진입차수 저장
		vector<vector<int>> rule(n + 1); // 규칙정보 저장
		vector<int> delay(n + 1); // 건설에 걸리는 시간 저장
		vector<int> cur(n + 1, 0); // 현재까지의 건설시간 저장

		for (int i = 1; i <= n; i++) {
			cin >> delay[i];
		}

		while (k--) {
			int x, y; cin >> x >> y;
			rule[x].push_back(y);
			degree[y]++;
		}

		int w; cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!degree[i]) { // 진입차수가 없는 경우
				q.push(i);
				cur[i] = delay[i]; //해당 건물의 건설기간이 현재까지의 건설시간
			}
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : rule[x]) {
				cur[y] = max(cur[y], cur[x] + delay[y]); // 선수 건물들 중 가장 건설시간이 오래걸리는 건물로 유지
				degree[y]--; // 선수 건물의 건설이 완료되었다면 진입차수--

				if (!degree[y]) { // 모든 선수 건물들의 건설이 끝났다면 queue에 삽입
					q.push(y);
				}
			}
		}

		cout << cur[w] << '\n';
	}
}