#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<pair<int, int>> pq; // 소요시간이 가장 적은 정점을 구하기 위한 priority_queue
	int INF = 200000, i, j, ans; // 최악의 소요시간보다 큰 값
	int n, m, x, a, b, t;
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> edge(n + 1); // 문제에서 주어지는 방향의 그래프
	vector<vector<pair<int, int>>> redge(n + 1); // 역방향 그래프(마을에서 x에 도달하는데 걸리는 시간 == 역방향 그래프에서 x에서 마을에 도달하는데 걸리는 시간)
	vector<int> time(n + 1, INF); time[x] = 0; // x에서 다시 각 정점으로 돌아가는데 걸리는 시간을 저장
	vector<int> rtime(n + 1, INF); rtime[x] = 0; // 각 정점에서 x에 도달하는데까지 걸리는 시간을 저장

	while (m--) {
		cin >> a >> b >> t;
		edge[a].push_back(make_pair(t, b));
		redge[b].push_back(make_pair(t, a));
	}

	pq.push(make_pair(rtime[x], x)); // 각 마을 -> x
	while (!pq.empty()) {
		j = pq.top().second;
		pq.pop();
		for (pair<int, int> k : redge[j]) {
			if (rtime[k.second] > rtime[j] + k.first) {
				rtime[k.second] = rtime[j] + k.first;
				pq.push(make_pair(-rtime[k.second], k.second));
			}
		}
	}

	pq.push(make_pair(time[x], x)); // x -> 각 마을
	while (!pq.empty()) {
		j = pq.top().second;
		pq.pop();
		for (pair<int, int> k : edge[j]) {
			if (time[k.second] > time[j] + k.first) {
				time[k.second] = time[j] + k.first;
				pq.push(make_pair(-time[k.second], k.second));
			}
		}
	}

	ans = time[1] + rtime[1];
	for (i = 2; i <= n; i++) {
		if (ans < time[i] + rtime[i]) {
			ans = time[i] + rtime[i];
		}
	}

	cout << ans;
}