#include <iostream>
#include <vector>
using namespace std;

const int INF = 1'000'000'007;

vector<pair<int, int>> sTree;

void build(vector<int>& v, int nodeIdx, int left, int right) {
    if (left == right) {
        sTree[nodeIdx] = { v[left], v[left] };
        return;
    }

    int mid = (left + right) / 2;
    build(v, nodeIdx * 2, left, mid);
    build(v, nodeIdx * 2 + 1, mid + 1, right);
    sTree[nodeIdx] = { min(sTree[nodeIdx * 2].first, sTree[nodeIdx * 2 + 1].first), max(sTree[nodeIdx * 2].second, sTree[nodeIdx * 2 + 1].second) };
}

pair<int, int> query(int a, int b, int nodeIdx, int left, int right) {
    if (b < left || right < a) return { INF, 0 };
    if (a <= left && right <= b) return sTree[nodeIdx];

    int mid = (left + right) / 2;
    pair<int, int> leftMinMax = query(a, b, nodeIdx * 2, left, mid);
    pair<int, int> rightMinMax = query(a, b, nodeIdx * 2 + 1, mid + 1, right);
    return { min(leftMinMax.first, rightMinMax.first), max(leftMinMax.second, rightMinMax.second) };
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    sTree.resize(4 * n);
    vector<int> v(n + 1); for (int i = 1; i <= n; i++) cin >> v[i];

    build(v, 1, 1, n);

    while (m--) {
        int a, b; cin >> a >> b;
        cout << query(a, b, 1, 1, n).first << ' ' << query(a, b, 1, 1, n).second << '\n';
    }
}