#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, j, i, k, ans = 0;
    cin >> n;
    vector<pair<int, int>> p(n);
    vector<vector<int>> s(n, vector<int>(100, -1)); // n: 사람 수, 101: 체력소모량, 저장값: 총 기쁨
    for (i = 0; i < n; i++) {
        cin >> l; // 체력
        p[i].first = l;
    }
    for (i = 0; i < n; i++) {
        cin >> j; // 기쁨
        p[i].second = j;
    }
    s[0][0] = 0;
    if (p[0].first < 100) // 100인 경우 Out of Range
        s[0][p[0].first] = p[0].second;
    for (i = 1; i < n; i++) {
        for (k = 0; k <= 100; k++) {
            if (k >= p[i].first && s[i - 1][k - p[i].first] != -1)
                s[i][k] = max(s[i - 1][k], s[i - 1][k - p[i].first] + p[i].second);
            else
                s[i][k] = s[i - 1][k];
        }
    }
    for (i = 0; i < 100; i++)
        if (ans < s[n - 1][i])
            ans = s[n - 1][i];
    cout << ans;
}