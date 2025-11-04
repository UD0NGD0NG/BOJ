#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> degree(n + 1, 0);
	vector<vector<int>> edge(n + 1);
	vector<pair<int, int>> time(n + 1, { 0, 0 });

	for (int i = 1; i <= n; i++) {
		cin >> time[i].first;
		int task_cnt; cin >> task_cnt;
		while (task_cnt--) {
			int task_num; cin >> task_num;

			edge[task_num].push_back(i);
			degree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int task : edge[cur]) {
			degree[task]--;
			
			if (time[task].second) {
				time[task].second = max(time[task].second, time[cur].first + time[cur].second);
			}
			else {
				time[task].second = time[cur].first + time[cur].second;
			}
			

			if (!degree[task]) {
				q.push(task);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, time[i].first + time[i].second);
	}

	cout << ans;
}