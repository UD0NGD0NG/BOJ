#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    bool flag; // 관계 중복 여부
    vector<vector<int>> edge(n + 1); // 관계 정보 저장
    while (m--) {
        flag = true;
        int a, b; cin >> a >> b;

        for (int x : edge[a]) {
            if (x == b) flag = false;
        }

        if (flag) {
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
    }

    int kb = 5001 * 2500;
    int num = 100;

    for (int i = 1; i <= n; i++) {
        vector<int> dist(n + 1, -1); dist[i] = 0; // 거리가 -1이면 아직 방문하지 않은 정점
        queue<int> q; q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : edge[x]) {
                if (dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        }

        int sum = 1; // dist[0] = -1이기에 1로 초기화
        for (int x : dist) {
            sum += x;
        }

        if (kb > sum) {
            kb = sum;
            num = i; // i가 작은값부터 탐색하므로 자동으로 번호가 가장 작은 사람으로 유지됨
        }
    }

    cout << num;
}