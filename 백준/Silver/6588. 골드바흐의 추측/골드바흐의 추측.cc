#include <iostream>
#include <vector>
#include <set>
using namespace std;

void Prime(vector<int>& v) { // 에라토스테네스의 체
    v[0] = 0;
    v[1] = 0;
    for (int i = 2; i < v.size(); i++) {
        if (v[i])
            for (int j = 2; i * j < v.size(); j++)
                v[i * j] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v(1000001);
    for (int i = 1; i < 1000001; i++)
        v[i] = i;
    Prime(v);

    while (1) {
        int n; cin >> n;

        if (!n) { // n이 0이면 종료
            break;
        }

        for (int i = 3; i < 500000; i += 2) { // 홀수인 두 소수의 합이므로 홀수만 탐색
            if (v[i] && v[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
    }
}