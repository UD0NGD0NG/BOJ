#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int INF = 100'000'000; // 최악의 경우 소모되는 비용
	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> bus(n + 1);
	while (m--) {
		int start, end, cost; cin >> start >> end >> cost;

		bool flag = true; // 출발지와 도착지가 같은 버스 중복 여부
		for (int i = 0; i < bus[start].size(); i++) {
			if (bus[start][i].second == end) { // 출발지와 도착지가 같은 버스가 있다면
				bus[start][i].first = min(bus[start][i].first, cost); // 더 적은 비용을 소모하는 정보로 갱신
				flag = false; // 새로 정보추가 제한
			}
		}
		if (flag) bus[start].push_back(make_pair(cost, end)); // 출발지와 도착지가 같은 버스가 없다면 맨 뒤에 정보 추가
	}

	int current, goal; cin >> current >> goal;
	vector<int> dist(n + 1, INF); dist[current] = 0; // 출발지로부터 출발지 까지의 비용 = 0, 나머지 도시는 최댓값으로 초기화

	priority_queue<pair<int, int>> pq; pq.push(make_pair(-dist[current], current));

	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();

		for (pair<int, int> y : bus[x]) { // 현재 도시에서 특정 도시로 갈때
			if (dist[y.second] > dist[x] + y.first) { // 더 적은 비용으로 갈 수 있다면
				dist[y.second] = dist[x] + y.first; // 비용을 갱신해주고
				pq.push(make_pair(-dist[y.second], y.second)); // 아직 방문하지 않은 도시중 가장 비용이 적은 비용을 사용하는 도시가 pq의 top에 오도록 설정
			}
		}
	}

	cout << dist[goal];
}