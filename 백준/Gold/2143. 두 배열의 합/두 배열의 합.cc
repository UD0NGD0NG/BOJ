#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> f(vector<int>& arr) {
    unordered_map<int, long long> res;
    int n = arr.size();
    vector<int> pre(1, 0);
    long long sum = 0;
    
    for (int a : arr) {
        sum += a;
        pre.push_back(sum);
    }

    for (int i = 0; i < pre.size(); i++) {
        for (int j = i + 1; j < pre.size(); j++) {
            res[pre[j] - pre[i]]++;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    unordered_map<int, long long> sumA = f(A);

    int m; cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    unordered_map<int, long long> sumB = f(B);
    
    long long ans = 0;
    for (auto a : sumA) {
        if (sumB.find(t - a.first) != sumB.end())
        ans += a.second * sumB[t - a.first];
    }
    cout << ans;
}