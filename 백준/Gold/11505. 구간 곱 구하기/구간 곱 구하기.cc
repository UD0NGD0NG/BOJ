#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

const int MOD = 1'000'000'007;

vector<ull> sTree;

void build(vector<ull>& v, int nodeIdx, int left, int right) {
    if (left == right) {
        sTree[nodeIdx] = v[left];
        return;
    }

    int mid = (left + right) / 2;
    build(v, nodeIdx * 2, left, mid);
    build(v, nodeIdx * 2 + 1, mid + 1, right);
    sTree[nodeIdx] = ((sTree[nodeIdx * 2]) % MOD * (sTree[nodeIdx * 2 + 1] % MOD)) % MOD;
}

void update(ull b, ull c, int nodeIdx, int left, int right) {
    if (left == right) {
        sTree[nodeIdx] = c;
        return;
    }

    ull mid = (left + right) / 2;
    if (b <= mid) {
        update(b, c, nodeIdx * 2, left, mid);
    }
    else {
        update(b, c, nodeIdx * 2 + 1, mid + 1, right);
    }

    sTree[nodeIdx] = ((sTree[nodeIdx * 2]) % MOD * (sTree[nodeIdx * 2 + 1] % MOD)) % MOD;
}

ull query(ull b, ull c, int nodeIdx, int left, int right) {
    if (c < left || right < b) return 1;
    if (b <= left && right <= c) return sTree[nodeIdx];

    int mid = (left + right) / 2;
    ull leftMul = query(b, c, nodeIdx * 2, left, mid);
    ull rightMul = query(b, c, nodeIdx * 2 + 1, mid + 1, right);
    return ((leftMul % MOD) * (rightMul % MOD)) % MOD;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    sTree.resize(4 * n);
    vector<ull> v(n + 1); for (int i = 1; i <= n; i++) cin >> v[i];

    build(v, 1, 1, n);

    int q = m + k;
    while (q--) {
        ull a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            update(b, c, 1, 1, n);
        }
        else {
            cout << query(b, c, 1, 1, n) << '\n';
        }
    }
}