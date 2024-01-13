#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queue<int> q; // bfs를 위한 queue
    int a, k; // a는 시작하는 수, b는 목표 수
    cin >> a >> k;
    vector<int> v(k + 1, 0); // 1 based를 위해 (k + 1)개의 값을 가진 vector생성, vector는 연산횟수를 저장
    v[a] = 0; // 시작하는 곳에 도달하기 위한 연산수는 0
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x + 1 <= k && !v[x + 1]) { // 범위
            q.push(x + 1);
            v[x + 1] = v[x] + 1;
        }
        if (x * 2 <= k && !v[x * 2]) { // 체크
            q.push(x * 2);
            v[x * 2] = v[x] + 1;
        }
    }
    cout << v[k];
}