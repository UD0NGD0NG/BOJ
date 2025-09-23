#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int l, n; cin >> l >> n;
		pair<int, int> ans({ 0, 0 });

		for (int i = 0; i < n; i++) {
			int w; cin >> w;
			ans.first = max(ans.first, min(w, l - w));
			ans.second = max(ans.second, max(w, l - w));
		}
		
		cout << ans.first << ' ' << ans.second << '\n';
	}
}