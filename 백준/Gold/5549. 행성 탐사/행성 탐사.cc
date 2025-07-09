#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n, k; cin >> m >> n >> k;
	vector<vector<char>> map(m + 1, vector<char>(n + 1));
	vector<vector<tuple<int, int, int>>> sum(m + 1, vector<tuple<int, int, int>>(n + 1, make_tuple(0, 0, 0)));
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 'J') {
				sum[i][j] = make_tuple(get<0>(sum[i - 1][j]) + get<0>(sum[i][j - 1]) - get<0>(sum[i - 1][j - 1]) + 1, get<1>(sum[i - 1][j]) + get<1>(sum[i][j - 1]) - get<1>(sum[i - 1][j - 1]), get<2>(sum[i - 1][j]) + get<2>(sum[i][j - 1]) - get<2>(sum[i - 1][j - 1]));
			}
			else if (map[i][j] == 'O') {
				sum[i][j] = make_tuple(get<0>(sum[i - 1][j]) + get<0>(sum[i][j - 1]) - get<0>(sum[i - 1][j - 1]), get<1>(sum[i - 1][j]) + get<1>(sum[i][j - 1]) - get<1>(sum[i - 1][j - 1]) + 1, get<2>(sum[i - 1][j]) + get<2>(sum[i][j - 1]) - get<2>(sum[i - 1][j - 1]));
			}
			else {
				sum[i][j] = make_tuple(get<0>(sum[i - 1][j]) + get<0>(sum[i][j - 1]) - get<0>(sum[i - 1][j - 1]), get<1>(sum[i - 1][j]) + get<1>(sum[i][j - 1]) - get<1>(sum[i - 1][j - 1]), get<2>(sum[i - 1][j]) + get<2>(sum[i][j - 1]) - get<2>(sum[i - 1][j - 1]) + 1);
			}
		}
	}

	while (k--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << get<0>(sum[c][d]) - get<0>(sum[a - 1][d]) - get<0>(sum[c][b - 1]) + get<0>(sum[a - 1][b - 1]) << ' ';
		cout << get<1>(sum[c][d]) - get<1>(sum[a - 1][d]) - get<1>(sum[c][b - 1]) + get<1>(sum[a - 1][b - 1]) << ' ';
		cout << get<2>(sum[c][d]) - get<2>(sum[a - 1][d]) - get<2>(sum[c][b - 1]) + get<2>(sum[a - 1][b - 1]) << '\n';
	}
}