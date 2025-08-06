#include <iostream>
#include <vector>
using namespace std;
using node = pair<int, int>; // minVal, idx

const int INF = 1'000'000'007;

vector<node> sTree;

void build(vector<int>& A, int nodeIdx, int left, int right) {
    if (left == right) {
        sTree[nodeIdx] = { A[left], left };
        return;
    }

    int mid = (left + right) / 2;
    build(A, nodeIdx * 2, left, mid);
    build(A, nodeIdx * 2 + 1, mid + 1, right);
    sTree[nodeIdx] = sTree[nodeIdx * 2].first > sTree[nodeIdx * 2 + 1].first ? sTree[nodeIdx * 2 + 1] : sTree[nodeIdx * 2];
}

void update(int i, int v, int nodeIdx, int left, int right) {
    if (left == right) {
        sTree[nodeIdx] = { v, i };
        return;
    }

    int mid = (left + right) / 2;
    if (i <= mid) {
        update(i, v, nodeIdx * 2, left, mid);
    }
    else {
        update(i, v, nodeIdx * 2 + 1, mid + 1, right);
    }
    sTree[nodeIdx] = sTree[nodeIdx * 2].first > sTree[nodeIdx * 2 + 1].first ? sTree[nodeIdx * 2 + 1] : sTree[nodeIdx * 2];
}

node query(int i, int j, int nodeIdx, int left, int right) {
    if (j < left || right < i) return { INF, -1 };
    if (i <= left && right <= j) return sTree[nodeIdx];

    int mid = (left + right) / 2;
    node leftNode = query(i, j, nodeIdx * 2, left, mid);
    node rightNode = query(i, j, nodeIdx * 2 + 1, mid + 1, right);
    return leftNode.first > rightNode.first ? rightNode : leftNode;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    sTree.resize(4 * n);
    vector<int> A(n + 1); for (int idx = 1; idx <= n; idx++) cin >> A[idx];

    build(A, 1, 1, n);

    int m; cin >> m;
    while (m--) {
        int q, i; cin >> q >> i;
        if (q == 1) {
            int v; cin >> v;
            update(i, v, 1, 1, n);
        }
        else {
            int j; cin >> j;
            cout << query(i, j, 1, 1, n).second << '\n';
        }
    }
}