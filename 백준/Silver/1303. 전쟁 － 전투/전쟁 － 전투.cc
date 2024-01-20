#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queue<pair<int, int>> q; // bfs를 위한 queue
    vector<int> I = { -1, 0, 1, 0 }, J = { 0, 1, 0, -1 }; // 상하좌우 순회
    int n, m, i, j, friendly = 0, enemy = 0, f, e, idx;
    cin >> n >> m; // n이 가로, m이 세로임을 주의
    vector<vector<char>> v(m + 2, vector<char>(n + 2, ' ')); // 바깥쪽은 공백으로 초기화를 하여 탐색을 하더라도 영향을 주지 않음
    vector<vector<bool>> visit(m + 2, vector<bool>(n + 2, false));
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            cin >> v[i][j];
    for (i = 1; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (v[i][j] == 'W' && !visit[i][j]) { // W는 아군
                f = 1; // 아직 탐색하지 않은 아군이 있음 -> 1로 초기화
                q.push(make_pair(i, j));
                visit[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> x = q.front();
                    q.pop();
                    for (idx = 0; idx < 4; idx++) {
                        if (v[x.first + I[idx]][x.second + J[idx]] == 'W' && !visit[x.first + I[idx]][x.second + J[idx]]) {
                            visit[x.first + I[idx]][x.second + J[idx]] = true;
                            q.push(make_pair(x.first + I[idx], x.second + J[idx]));
                            f++; // 아직 탐색하지 않은 인접한 위치에 아군이 존재한다면 아군 수 +1
                        }
                    }
                }
                friendly += f * f; // 위력은 병사수의 제곱
            }
            if (v[i][j] == 'B' && !visit[i][j]) { //B는 적군
                e = 1;
                q.push(make_pair(i, j));
                visit[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> x = q.front();
                    q.pop();
                    for (idx = 0; idx < 4; idx++) {
                        if (v[x.first + I[idx]][x.second + J[idx]] == 'B' && !visit[x.first + I[idx]][x.second + J[idx]]) {
                            visit[x.first + I[idx]][x.second + J[idx]] = true;
                            q.push(make_pair(x.first + I[idx], x.second + J[idx]));
                            e++;
                        }
                    }
                }
                enemy += e * e;
            }
        }
    }
    cout << friendly << ' ' << enemy;
}