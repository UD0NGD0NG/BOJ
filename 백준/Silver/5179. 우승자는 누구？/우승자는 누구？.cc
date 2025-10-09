#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K; cin >> K;
	for (int idx = 1; idx <= K; idx++) {
		int M, N, P; cin >> M >> N >> P;
		vector<pair<int, int>> score(N + 1, { 0, 0 });
		vector<vector<int>> solve(N + 1, vector<int>(M, 0));
		vector<vector<int>> cnt(N + 1, vector<int>(M, 0));
		while (N--) {
			int p, t, j; char m; cin >> p >> m >> t >> j;
			if (!solve[p][m - 'A']) {
				if (j) {
					score[p].first += t + cnt[p][m - 'A'] * 20;
					score[p].second++;
					solve[p][m - 'A']++;
				}
				else {
					cnt[p][m - 'A']++;
				}
			}
		}

		priority_queue<tuple<int, int, int>> pq;
		for (int i = 1; i <= P; i++) {
			pq.push(make_tuple(score[i].second, -score[i].first, i));
		}

		cout << "Data Set " << idx << ":\n";
		while (!pq.empty()) {
			cout << get<2>(pq.top()) << ' ' << get<0>(pq.top()) << ' ' << -get<1>(pq.top()) << '\n';
			pq.pop();
		}
		cout << '\n';
	}
}