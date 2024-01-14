#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q;
	vector<vector<int>> v(7, vector<int>(7, -1)); // 보드의 격자판, 맨 바깥 줄은 접근 불가이므로 -1로 초기화
	vector<vector<int>> dist(7, vector<int>(7, -1)); // 시작점으로 부터의 거리를 저장하는 벡터, 0으로 초기화해도 됨
	vector<pair<int, int>> one; // 1의 위치를 저장하는 벡터
	vector<int> I = { -1, 0, 1, 0 }, J = { 0, 1, 0, -1 }; // 상하좌우 탐색을 위한 벡터
	int i, j, r, c, idx, min = 100; // 최솟값은 25보다만 큰 수면 상관 X
	for (i = 1; i < 6; i++) {
		for (j = 1; j < 6; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) // 1인 격자 저장
				one.push_back(make_pair(i, j));
		}
	}
	cin >> r >> c;
	q.push(make_pair(r + 1, c + 1)); // 시작 격자, 1-based이기에 각각 +1 한 후 queue에 삽입
	dist[r + 1][c + 1] = 0; // 시작점으로부터 시작점까지의 거리는 0
	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		for (idx = 0; idx < 4; idx++) {
			if (dist[x.first + I[idx]][x.second + J[idx]] == -1 && v[x.first + I[idx]][x.second + J[idx]] != -1) {
				dist[x.first + I[idx]][x.second + J[idx]] = dist[x.first][x.second] + 1;
				q.push(make_pair(x.first + I[idx], x.second + J[idx]));
			}
		}
	}
	for (i = 0; i < one.size(); i++) // 1인 격자의 dist(거리)가 -1이 아니면 최솟값 비교 연산 진행
		if (dist[one[i].first][one[i].second] != -1 && min > dist[one[i].first][one[i].second])
			min = dist[one[i].first][one[i].second];
	if (min == 100) // 1인 격자의 dist가 모두 -1일 경우 min의 값은 초기값과 동일
		cout << -1;
	else
		cout << min;
}