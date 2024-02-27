#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int ans = 1, len = 1;

	while (len != min(n, m)) {
		bool flag = false;

		for (int i = 0; i < n - len; i++) {
			for (int j = 0; j < m - len; j++) {
				if (v[i][j] == v[i + len][j] && v[i + len][j] == v[i][j + len] && v[i][j + len] == v[i + len][j + len]) { // 한변의 길이가 (len + 1)인 정사각형을 만들 수 있는 경우
					++len, ans = len;
					flag = true;
				}

				if (flag) break;
			}

			if (flag) break;
		}

		if (!flag) len++; // line22의 for문 안에서 len값의 갱신이 없을 경우에만 len++
	}

	cout << ans * ans; // 넓이 == 거리^2
}