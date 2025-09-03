#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	vector<int> sq(4);
	while (n != 1) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				sq[0] = v[i * 2][j * 2];
				sq[1] = v[i * 2][j * 2 + 1];
				sq[2] = v[i * 2 + 1][j * 2];
				sq[3] = v[i * 2 + 1][j * 2 + 1];
				sort(sq.begin(), sq.end());
				v[i][j] = sq[2];
			}
		}

		n /= 2;
	}

	cout << v[0][0];
}