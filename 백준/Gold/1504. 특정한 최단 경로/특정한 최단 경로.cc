#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<pair<int, int>> pq; // search smallest distance
    int INF = 800000, i;
    int n, e, a, b, c, v1, v2; // same with problem
    int ans1 = 0, ans2 = 0, flag1 = 1, flag2 = 1; // 1 -> v1 -> v2 -> n , 1 -> v2 -> v1 -> n
    
    cin >> n >> e;
    vector<int> dist(n + 1, INF); dist[1] = 0;
    vector<vector<pair<int, int>>> edge(n + 1);
    
    while (e--) { // build graph
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(c, b));
        edge[b].push_back(make_pair(c, a));
    }
    
    cin >> v1 >> v2;
    pq.push(make_pair(dist[1], 1)); // 1 -> (v1 || v2)
    
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        for (pair<int, int> y : edge[x]) {
            if (dist[y.second] > dist[x] + y.first) {
                dist[y.second] = dist[x] + y.first;
                pq.push(make_pair(-dist[y.second], y.second));
            }
        }
    }
    
    if (dist[v1] == INF) flag1 = 0; // there is no edge between 1, v1
    else ans1 += dist[v1];
    if (dist[v2] == INF) flag2 = 0; // there is no edge between 1, v2
    else ans2 += dist[v2];
    
    for (i = 1; i <= n; i++) dist[i] = INF; // initialize dist
    dist[v1] = 0; pq.push(make_pair(dist[v1], v1)); // set start node, v1 -> v2 == v2 -> v1
    
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        for (pair<int, int> y : edge[x]) {
            if (dist[y.second] > dist[x] + y.first) {
                dist[y.second] = dist[x] + y.first;
                pq.push(make_pair(-dist[y.second], y.second));
            }
        }
    }
    
    if (dist[v2] == INF) flag1 = 0, flag2 = 0; // there is no edge between v1, v2
    else ans1 += dist[v2], ans2 += dist[v2];
    
    for (i = 1; i <= n; i++) dist[i] = INF; // initialize dist
    dist[n] = 0; pq.push(make_pair(dist[n], n)); // set start node, n -> (v1 || v2)
    
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        for (pair<int, int> y : edge[x]) {
            if (dist[y.second] > dist[x] + y.first) {
                dist[y.second] = dist[x] + y.first;
                pq.push(make_pair(-dist[y.second], y.second));
            }
        }
    }
    
    if (dist[v2] == INF) flag1 = 0; // there is no edge between n, v2
    else ans1 += dist[v2];
    if (dist[v1] == INF) flag2 = 0; // there is no edge between n, v1
    else ans2 += dist[v1];
    
    if (flag1) {
        if (flag2) cout << min(ans1, ans2);
        else cout << ans1;
    }
    else {
        if (flag2) cout << ans2;
        else cout << -1;
    }
}