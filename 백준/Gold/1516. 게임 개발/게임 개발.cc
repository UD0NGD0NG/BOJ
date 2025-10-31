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
		int building = i;
		while (building != -1) {
			cin >> building;

			if (building != -1) {
				edge[building].push_back(i);
				degree[i]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int building : edge[cur]) {
			degree[building]--;
			
			if (time[building].second) {
				time[building].second = max(time[building].second, time[cur].first + time[cur].second);
			}
			else {
				time[building].second = time[cur].first + time[cur].second;
			}
			

			if (!degree[building]) {
				q.push(building);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << time[i].first + time[i].second << '\n';
	}
}