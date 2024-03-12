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

    vector<int> uf; for (int i = 0; i <= n; i++) uf.push_back(i);

    while (m--) {
        int o, a, b; cin >> o >> a >> b;

        if (o) { // o == 1
            if (Find(uf, a) == Find(uf, b)) cout << "YES\n"; // root가 같다면 같은 집합이므로 YES 출력
            else cout << "NO\n"; // 다르다면 NO 출력
        }
        else { // o == 0
            Union(uf, a, b); // 하나의 집합으로 만들기
        }
    }
}