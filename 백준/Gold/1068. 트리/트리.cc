#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // remove_if()
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> q;
	int n, i, p, r, cnt = 0, root;
	cin >> n;
	vector<vector<int>> edge(n);
	vector<bool> visit(n);
	for (i = 0; i < n; i++) {
		cin >> p;
		if (p != -1)
			edge[p].push_back(i);
		else
			root = i; // p가 -1인경우 root node로 설정
	}
	cin >> r;
	if (r == root) // root node가 삭제될 경우 0출력
		cout << 0;
	else {
		q.push(root);
		visit[root] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : edge[x])
				if (y == r)
					edge[x].erase(remove_if(edge[x].begin(), edge[x].end(), [r](int a)->bool {return a == r; }), edge[x].end()); // r이 자식으로 있을경우 해당 간선을 삭제
			for (int y : edge[x]) {
				if (!visit[y]) {
					visit[y] = true;
					q.push(y);
				}
			}
		}
		for (i = 0; i < n; i++)
			if (visit[i] && !edge[i].size()) // 방문여부를 확인하지 않을 시 삭제된 node의 자식 node도 검사하므로 방문처리 필수
				cnt++;
		cout << cnt;
	}
}