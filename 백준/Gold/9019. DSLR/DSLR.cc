#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;

		vector<pair<int, char>> ancestor(10001);
		vector<int> dist(10001, -1); dist[a] = 0;

		string cmd = "DSLR";
		queue<int> q; q.push(a);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			vector<int> dslr(4);
			dslr[0] = cur * 2 % 10000,
			dslr[1] = cur ? cur - 1 : 9999,
			dslr[2] = cur * 10 % 10000 + cur / 1000,
			dslr[3] = cur / 10 + (cur % 10) * 1000;

			for (int i = 0; i < 4; i++) {
				int next = dslr[i];
				if (dist[next] == -1 || dist[next] > dist[cur] + 1) {
					q.push(next);
					dist[next] = dist[cur] + 1;
					ancestor[next] = { cur, cmd[i] };
				}
			}
		}

		stack<char> st;
		while (b != a) {
			st.push(ancestor[b].second);
			b = ancestor[b].first;
		}

		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << '\n';
	}
}