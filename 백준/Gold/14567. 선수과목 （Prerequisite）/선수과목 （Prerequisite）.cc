#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, a, b, i;
	cin >> n >> m;

	vector<int> degree(n + 1, 0); // 진입 차수(In-degree)의 개수를 저장
	vector<int> semester(n + 1, 1); // 최소 학기 값 저장
	vector<vector<int>> edge(n + 1); // 그래프의 간선정보 저장
	queue<int> in; // 위상정렬(In-degree 방식)을 위한 queue

	while (m--) { // 그래프 구성
		cin >> a >> b;
		edge[a].push_back(b);
		degree[b]++; // 선수과목이 생긴 과목(도착 정점)의 진입 차수 값 1 늘려주기
	}

	for (int i = 1; i <= n; i++) {
		if (!degree[i]) in.push(i); // 진입 차수가 0인 과목(정점) queue에 넣기
	}

	while (!in.empty()) {
		int x = in.front();
		in.pop();

		for (int y : edge[x]) {
			degree[y]--;
			if (!degree[y]) { // 진입 차수가 0이 되면
				in.push(y); // queue에 넣어주고
				semester[y] = semester[x] + 1; // 최소 학기 값 갱신
			}
		}
	}

	for (i = 1; i <= n; i++) {
		cout << semester[i] << ' ';
	}
}