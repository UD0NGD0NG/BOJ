#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>& uf, int node) {
    if (uf[node] == node) return node;

    int root = Find(uf, uf[node]);
    uf[node] = root;
    return root;
}

void Union(vector<int>& uf, int node1, int node2) {
    int root1 = Find(uf, uf[node1]), root2 = Find(uf, uf[node2]);

    uf[root1] = root2;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    vector<int> uf(n + 1); for (int i = 1; i <= n; i++) uf[i] = i;;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int o; cin >> o;

            if (o) {
                Union(uf, i, j); // 서로 아는 사이(o == 1)
            }
        }
    }

    vector<int> route(m);
    for (int i = 0; i < m; i++) {
        cin >> route[i];
    }

    for (int i = 0; i < m - 1; i++) {
        if (Find(uf, route[i]) != Find(uf, route[i + 1])) { // 한번이라도 다음 도시로 가는 경로가 없는 경우
            cout << "NO"; // NO 출력후
            return 0; // 종료
        }
    }
    cout << "YES"; // 한번도 경로가 없는 경우가 없다면 YES 출력
}