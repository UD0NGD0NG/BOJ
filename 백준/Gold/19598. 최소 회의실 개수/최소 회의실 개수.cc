#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;
		v[i] = { s, e };
	}

	sort(v.begin(), v.end());

	int ans = 1;
	priority_queue<int> pq; pq.push(-v[0].second);
	for (int i = 1; i < n; i++) {
		while (!pq.empty() && v[i].first >= -pq.top()) pq.pop();
		pq.push(-v[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;
}