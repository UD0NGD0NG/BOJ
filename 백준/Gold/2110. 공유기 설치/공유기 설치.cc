#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pos;
int n, c;

bool IsPossible(int mid) {
    int cnt = 1, pre = pos.front(); // 맨 앞의 집에 공유기를 설치하고 시작
    for (int i = 1; i < n; i++) { // 모든 좌표를 탐색하며
        if (pos[i] - pre >= mid) { // 직전에 공유기를 설치한 집과 탐색하는 좌표간의 거리차이가 기준보다 크다면 공유기 설치
            pre = pos[i]; // 직전에 설치한 집 좌표 갱신
            cnt++; // 설치가능한 좌표수 + 1
        }
    }

    return cnt >= c; // 현재 거리를 기준으로 c개 이상의 공유기를 설치할 수 있다면 통과
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos.push_back(x);
    }

    sort(pos.begin(), pos.end());

    int left = 0, right = pos.back() - pos.front(), ans = 0; // 공유기간의 거리가 최대가 되는 길이는 집의 좌표중 최댓값과 최솟값의 차이
    while (left <= right) {
        int mid = (left + right) / 2;

        if (IsPossible(mid)) { // 현재 거리를 기준으로 공유기를 배치할 수 있다면 더 먼 거리도 가능한지 판단
            left = mid + 1;
            ans = mid;
        }
        else { // 현재 거리를 기준으로 배치할 수 없다면 더 짧은 거리는 가능한지 판단
            right = mid - 1;
        }
    }

    cout << ans;
}