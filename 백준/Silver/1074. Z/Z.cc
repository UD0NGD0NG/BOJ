#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, r, c, ans = 0, mod = 1, multi = 1;
    cin >> n >> r >> c;

    for (int i = 0; i < 15; i++) { // 처음에는 (n / 1) * (n / 1) 크기의 정사각형을 4부분으로 나누어 위치를 파악
        ans += (((r / mod) % 2) * 2 + ((c / mod) % 2)) * multi;
        mod *= 2, multi *= 4; // 정사각형의 범위를 세분화
    }

    cout << ans;
}