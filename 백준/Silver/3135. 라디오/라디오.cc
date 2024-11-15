#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool valid(int x) {
	return 0 < x && x < 1000;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> dist(1000, 1000);
	queue<int> q;

	int a, b; cin >> a >> b;
	dist[a] = 0;
	q.push(a);

	int n; cin >> n;
	while (n--) {
		cin >> a;

		if (dist[a]) {
			dist[a] = 1;
			q.push(a);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (valid(cur + 1) && dist[cur + 1] > dist[cur] + 1) {
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}
		if (valid(cur - 1) && dist[cur - 1] > dist[cur] + 1) {
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
	}

	cout << dist[b];
}