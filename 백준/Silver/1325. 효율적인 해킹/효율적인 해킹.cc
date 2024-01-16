#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> q;
	int n, m, a, b, i, max = 0;
	cin >> n >> m;
	vector<vector<int>> edge(n + 1); // 간선을 저장하는 vector
	vector<int> cnt(n + 1, 0); // 해킹한 컴퓨터의 개수를 저장하는 vector
	while (m--) {
		cin >> a >> b;
		edge[b].push_back(a); // b를 해킹시 a도 해킹되지만 a를 해킹한다해서 b가 해킹되지는 않음 -> 단방향 그래프
	}
	for (i = 1; i <= n; i++) {
		vector<bool> visit(n + 1, false); // 시작 node가 바뀔때마다 visit 초기화
		q.push(i);
		visit[i] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : edge[x]) {
				if (!visit[y]) {
					visit[y] = true;
					q.push(y);
					cnt[i]++; // 시작 node의 cnt vector값을 바꿔줘야함
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
		if (max < cnt[i])
			max = cnt[i];
	for (i = 1; i <= n; i++) // 자동 오름차순
		if (max == cnt[i])
			cout << i << ' ';
}
