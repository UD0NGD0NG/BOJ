#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<vector<int>> order(n + 1); // 순서 저장
	vector<int> degree(n + 1, 0); // 진입차수 저장

	while (m--) {
		int cnt; cin >> cnt;
		int pre = 0; // 직전 가수 저장
		while (cnt--) {
			int num; cin >> num;
			if (pre) { // tmp가 0이 아닌경우(해당 pd의 첫번째 가수가 아닌경우)
				degree[num]++; // 해당 가수의 진입차수를 1증가
				order[pre].push_back(num); // 순서 저장
			}

			pre = num; // 직전 가수 갱신
		}
	}

	queue<int> q; // 무대에 올라갈 수 있는 가수 저장
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) { // 진입차수가 0인 가수는 바로 무대에 올라갈 수 있음
			q.push(i);
		}
	}

	vector<int> ans; // 무대에 올라가는 순서 저장
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans.push_back(x);

		for (int y : order[x]) { // 해당 가수뒤에 나올 수 있는 가수들에 대해
			degree[y]--; // 진입차수를 1빼주고

			if (!degree[y]) { // 더이상 먼저 나와야하는 가수가 없다면
				q.push(y); // 무대에 올라갈 수 있도록 처리
			}
		}
	}

	if (ans.size() == n) { // 모든 가수가 무대에 올라갈 수 있는 경우
		for (int x : ans) {
			cout << x << '\n';
		}
	}
	else {
		cout << 0;
	}
}