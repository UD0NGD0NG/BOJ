#include <iostream>
#include <vector>
using namespace std;

bool check(int x, int x1, int y, int y1, double r) {
	return ((x - x1) * (x - x1) + (y - y1) * (y - y1)) <= (r * r);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<pair<int, int>> v;
	int n; double r; cin >> n >> r;

	while (n--) {
		int x, y; cin >> x >> y;
		v.push_back({ x, y });
	}

	int ans = 0, ansx = 0, ansy = 0;
	for (int x = -100; x <= 100; x++) {
		for (int y = -100; y <= 100; y++) {
			int cnt = 0;
			for (auto a : v) {
				if (check(x, a.first, y, a.second, r)) {
					cnt++;
				}
			}

			if (ans < cnt) {
				ans = cnt;
				ansx = x;
				ansy = y;
			}
		}
	}

	cout << ansx << ' ' << ansy;
}