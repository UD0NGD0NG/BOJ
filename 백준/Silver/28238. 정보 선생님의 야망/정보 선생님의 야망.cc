#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	int ans = 0, ansi = 0, ansj = 1;
	unordered_map<int, set<int>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int a; cin >> a;
			if (a) mp[i].insert(j);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) continue;

			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (mp[k].find(i) != mp[k].end() && mp[k].find(j) != mp[k].end()) {
					cnt++;
				}
			}
			if (ans < cnt) {
				ans = cnt, ansi = i, ansj = j;
			}
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < 5; i++) {
		cout << (ansi == i || ansj == i) << ' ';
	}
}