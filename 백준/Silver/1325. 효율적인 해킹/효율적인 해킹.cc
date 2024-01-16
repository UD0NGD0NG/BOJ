#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> q;
	int n, m, a, b, i, max = 0;
	cin >> n >> m;
	vector<vector<int>> edge(n + 1);
	vector<int> cnt(n + 1, 0);
	while (m--) {
		cin >> a >> b;
		edge[b].push_back(a); // 그래프 방향 다시 생각해보기
	}
	for (i = 1; i <= n; i++) {
		vector<bool> visit(n + 1, false);
		q.push(i);
		visit[i] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : edge[x]) {
				if (!visit[y]) {
					visit[y] = true;
					q.push(y);
					cnt[i]++;
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
		if (max < cnt[i])
			max = cnt[i];
	for (i = 1; i <= n; i++)
		if (max == cnt[i])
			cout << i << ' ';
}