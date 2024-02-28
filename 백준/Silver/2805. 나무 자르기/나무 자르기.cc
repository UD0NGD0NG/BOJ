#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

bool IsPossible(ll arr[], ll mid, ll n, ll m) {
    ll sum = 0; // 가져가는 나무의 합

    for (ll i = 0; i < n; i++) {
        sum += (arr[i] > mid ? arr[i] - mid : 0); // 잘리는 부분이 없다면(arr[i] - mid가 0보다 작다면) 0을 더함
    }

    return sum >= m; // 가져가는 나무의 합이 필요한 나무의 길이보다 길면 참
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll arr[1000000];
    ll n, m; cin >> n >> m;

    ll left = 0, right = 0; // 절단기에 설정할 수 있는 높이의 최솟값이 0이므로 left의 초기값은 0

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        right = max(right, arr[i]);
    }

    ll h = right - 1; // m의 최솟값이 1인경우 가장 큰 나무 - 1의 경우가 가능한 높이의 최댓값

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (IsPossible(arr, mid, n, m)) {
            left = mid + 1;
            h = mid;
        }
        else {
            right = mid - 1;
        }
    }

    cout << h;
}