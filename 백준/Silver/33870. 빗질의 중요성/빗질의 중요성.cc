#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
	vector<pair<int, int>> dog(n, {1, 0});

	while (m--) {
		int b; cin >> b; b--;
		if (dog[b].first <= a[b] || dog[b].second) {
			dog[b].first = 0;
		}

		for (int i = 0; i < n; i++) {
			dog[i].first++;
			dog[i].second = 0;
		}

		dog[b].second = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dog[i].first > a[i]) {
			ans++;
		}
	}

	cout << ans;
}