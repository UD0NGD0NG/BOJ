#include <iostream>
#include <algorithm>
using namespace std;

bool IsPossible(long arr[], long mid, long k, long n) {
    long cnt = 0; // 현재 mid값으로 만들 수 있는 랜선의 개수

    for (int i = 0; i < k; i++) {
        cnt += arr[i] / mid;
    }

    return cnt >= n; // n개 이상 만들 수 있으면 true 없으면 false 리턴
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long arr[10000];
    long k, n; cin >> k >> n;

    long left = 1, right = 0;

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        right = max(right, arr[i]); // 이분탐색의 오른쪽 값은 랜선 중 가장 긴 값으로 설정
    }

    long MAX = right + 1; // 랜선의 최댓값이 int형의 최댓값이기에 MAX의 자료형을 int로 선언시 overflow
    long ans = MAX;

    while (left <= right) {
        long mid = (left + right) / 2;
        if (IsPossible(arr, mid, k, n)) { // 현재 mid값으로 n개를 만들 수 있다면
            left = mid + 1; // 탐색범위를 더 큰쪽으로 변경하고
            ans = mid; // 정답을 갱신
        }
        else {
            right = mid - 1; // 만들 수 없다면 탐색범위를 더 작은쪽으로 변경
        }
    }

    if (MAX == ans) cout << 0; // 만들 수 없는 경우(정답 갱신이 일어나지 않음)
    else cout << ans;
}