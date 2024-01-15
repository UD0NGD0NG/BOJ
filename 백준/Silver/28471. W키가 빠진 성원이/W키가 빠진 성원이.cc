#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q;
	vector<int> I = { -1,-1,-1,0,0,1,1 }, J = { -1,0,1,-1,1,-1,1 };
	int n, i, j, idx, cnt = 0;
	string s;
	cin >> n;
	vector<vector<char>> v(n + 2, vector<char>(n + 2, '#'));
	vector<vector<bool>> visit(n + 2, vector<bool>(n + 2, false));
	for (i = 1; i <= n; i++) {
		cin >> s;
		for (j = 1; j <= n; j++) {
			v[i][j] = s[j - 1];
			if (v[i][j] == 'F') {
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		for (idx = 0; idx < 7; idx++) {
			if (v[x.first + I[idx]][x.second + J[idx]] != '#' && !visit[x.first + I[idx]][x.second + J[idx]]) {
				q.push(make_pair(x.first + I[idx], x.second + J[idx]));
				visit[x.first + I[idx]][x.second + J[idx]] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}