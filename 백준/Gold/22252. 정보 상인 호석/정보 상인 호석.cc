#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q; cin >> q;

	long long ans = 0;
	unordered_map<string, priority_queue<int>> info;
	while (q--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			string name; cin >> name;
			int k; cin >> k;
			while (k--) {
				int c; cin >> c;
				info[name].push(c);
			}
		}
		else {
			string name; cin >> name;
			int b; cin >> b; b = min(b, (int)info[name].size());
			for (int i = 0; i < b; i++) {
				ans += info[name].top();
				info[name].pop();
			}
		}
	}

	cout << ans;
}