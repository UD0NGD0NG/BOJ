#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 100000000;

	int t; cin >> t;
	while (t--) {
		int n, d, c; cin >> n >> d >> c;

		vector<vector<pair<int, int>>> edge(n + 1);
		while (d--) { // make graph
			int a, b, s; cin >> a >> b >> s;
			edge[b].push_back(make_pair(s, a));
		}
		// 해당 컴퓨터가 감염되는데까지 걸린 시간 저장
		vector<int> time(n + 1, INF); time[c] = 0; // 최초 감염 컴퓨터는 0, 나머지는 최대치

		set<int> infect; infect.insert(c); // 감염된 컴퓨터 번호 저장
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, c));
		while (!pq.empty()) {
			int x = pq.top().second; // current index
			pq.pop();
			for (pair<int, int> y : edge[x]) {
				if (time[y.second] != min(time[y.second], time[x] + y.first)) {
					time[y.second] = time[x] + y.first;
					pq.push({ -time[y.second], y.second }); // 최솟값으로 갱신되었다면 push(다익스트라)
					infect.insert(y.second);
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (time[i] != INF) ans = max(ans, time[i]);
		}
		cout << infect.size() << ' ' << ans << '\n';
	}
}