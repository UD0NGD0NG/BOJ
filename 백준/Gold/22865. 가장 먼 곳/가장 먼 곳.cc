#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1'000'000'001;

bool arrive(int a, int b, int c) {
	return a != INF && b != INF && c != INF;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a, b, c; cin >> a >> b >> c;
	int m; cin >> m;
	vector<vector<pair<int, int>>> edge(n + 1);

	while (m--) {
		int d, e, l; cin >> d >> e >> l;

		edge[d].push_back(make_pair(l, e));
		edge[e].push_back(make_pair(l, d));
	}

	vector<int> dista(n + 1, INF); dista[a] = 0; // A가 사는 위치에서부터 위치 X까지의 거리
	vector<int> distb(n + 1, INF); distb[b] = 0; // B가 사는 위치에서부터 위치 X까지의 거리
	vector<int> distc(n + 1, INF); distc[c] = 0; // C가 사는 위치에서부터 위치 X까지의 거리

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, a)); // A가 사는 위치를 기준으로 다익스트라 1회
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (dista[y.second] != min(dista[y.second], dista[x] + y.first)) {
				dista[y.second] = min(dista[y.second], dista[x] + y.first);
				pq.push(make_pair(-dista[y.second], y.second));
			}
		}
	}

	pq.push(make_pair(0, b)); // B가 사는 위치를 기준으로 다익스트라 1회
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (distb[y.second] != min(distb[y.second], distb[x] + y.first)) {
				distb[y.second] = min(distb[y.second], distb[x] + y.first);
				pq.push(make_pair(-distb[y.second], y.second));
			}
		}
	}

	pq.push(make_pair(0, c)); // C가 사는 위치를 기준으로 다익스트라 1회
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (pair<int, int> y : edge[x]) {
			if (distc[y.second] != min(distc[y.second], distc[x] + y.first)) {
				distc[y.second] = min(distc[y.second], distc[x] + y.first);
				pq.push(make_pair(-distc[y.second], y.second));
			}
		}
	}

	pair<int, int> ans = { 0, n + 1 };
	for (int i = 1; i <= n; i++) { // 각각의 위치들에 대하여
		if (arrive(dista[i], distb[i], distc[i])) { // A, B, C모두 도달할 수 있는 곳이라면
			int candidate = min(dista[i], min(distb[i], distc[i])); // 해당 위치를 후보지로 선정

			if (ans.first < candidate) { // 후보지의 땅 번호가 더 작다면
				ans = { candidate, i }; // 정답으로 설정
			}
		}
	}

	cout << ans.second;
}