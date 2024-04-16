#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    int a; cin >> a; // 1번 우선 선택
    int cur_sum = a, max_sum = a;

    for (int i = 1; i < n; i++) {
        cin >> a;

        if (cur_sum > 0) cur_sum += a; // 현재 합이 양수인경우 a추가
        else cur_sum = a; // 음수인 경우 a + 현재합 <= a 이므로 a를 현재 합으로

        max_sum = max_sum > cur_sum ? max_sum : cur_sum; // 현재 합이 최대합보다 크다면 값 갱신
    }

    cout << max_sum;
}