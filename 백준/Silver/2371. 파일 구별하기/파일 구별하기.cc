#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	unordered_map<int, set<int>> t;
	unordered_map<int, int> l;

	int maxIdx = 0;
	for (int i = 0; i < n; i++) {
		int f = 0, idx = 1;
		while (1) {
			cin >> f;
			if (f == -1) break;
			l[idx]++;
			maxIdx = max(maxIdx, idx);
			t[idx++].insert(f);
		}
	}

	for (int i = 1; i <= maxIdx; i++) {
		if (t[i].size() == l[i]) {
			cout << i;
			return 0;
		}
	}
}