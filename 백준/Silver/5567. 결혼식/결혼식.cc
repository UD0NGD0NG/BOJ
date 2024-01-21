#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> f; // 상근이의 친구를 저장
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> edge(n + 1);
    vector<bool> visit(n + 1, false);
    while (m--) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    visit[1] = true; // 상근이는 우선 방문처리
    for (int x : edge[1]) { // 상근이의 친구들
        cnt++;
        visit[x] = true;
        f.push_back(x);
    }
    for (int y : f) {
        for (int z : edge[y]) { // 상근이의 친구들의 친구
            if (!visit[z]) {
                cnt++;
                visit[z] = true;
            }
        }
    }
    cout << cnt;
}