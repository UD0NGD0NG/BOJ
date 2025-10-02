#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pq.push(a);
	}

	int time = 0;
	while (!pq.empty()) {
		int a = pq.top(); pq.pop();

		if (!pq.empty()) {
			int b = pq.top(); pq.pop();
			
			if (b - 1) pq.push(b - 1);
		}

		if (a - 1) pq.push(a - 1);

		time++;

		if (time == 1441) {
			cout << -1;
			return 0;
		}
	}

	(time > 1440) ? cout << -1 : cout << time;
}