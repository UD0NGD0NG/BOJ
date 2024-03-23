#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[100001] = {};
    int n, s; cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = n + 1; // 초기값은 정답이 될 수 없는 값중 가장 작은값으로 설정(배열의 길이 + 1)

    int sum_val = 0;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j + 1 <= n && sum_val + arr[j + 1] < s) { // 합이 s보다 작을때까지 오른쪽 포인터를 옮긴 후
            sum_val += arr[j + 1];
            j++;
        }

        if (sum_val + arr[j + 1] >= s) // 오른쪽 포인터의 다음수를 더했을 때 s이상인 경우 최소 길이 갱신
            ans = min(ans, j - i + 2);

        sum_val -= arr[i]; // 왼쪽 포인터를 옮길때 누적합에서 왼쪽 포인터 값 빼주기
    }

    if (ans == n + 1) cout << 0; // 최소 길이의 갱신이 없었다면(s이상을 만들수 있는 경우가 없다면) 0 출력
    else cout << ans;

    return 0;
}