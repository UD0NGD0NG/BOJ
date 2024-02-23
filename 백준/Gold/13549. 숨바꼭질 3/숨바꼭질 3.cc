#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<pair<int, int>> pq;
    constexpr int LIMIT = 100'000; // 최대 인덱스 && 최대 거리값
    int n, k; cin >> n >> k;

    vector<int> dist(100001, LIMIT); dist[n] = 0; // 도달가능한 모든 정점의 거리값을 최대로 설정, 시작 정점의 거리값은 0으로 초기화
    pq.push(make_pair(dist[n], n)); // 처음에는 시작점만 우선순위 큐에 삽입

    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();

        if (x * 2 <= LIMIT && dist[x * 2] > dist[x]) { // 거리값이 갱신될 경우에
            dist[x * 2] = dist[x];
            pq.push(make_pair(-dist[x * 2], x * 2)); // 해당 정점도 우선순위 큐에 삽입
        }

        if (x + 1 <= LIMIT && dist[x + 1] > dist[x] + 1) {
            dist[x + 1] = dist[x] + 1;
            pq.push(make_pair(-dist[x + 1], x + 1));
        }

        if (x - 1 >= 0 && dist[x - 1] > dist[x] + 1) {
            dist[x - 1] = dist[x] + 1;
            pq.push(make_pair(-dist[x - 1], x - 1));
        }
    }

    cout << dist[k];
}