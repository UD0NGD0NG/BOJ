#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unordered_map<int, int> mp;
	for (int i = 1; i <= 2'000'000; i++) {
		mp[i] = 0;
	}

	int n; cin >> n;
	for (int idx = 1; idx <= n; idx++) {
		int s; cin >> s;
		if (!mp[s]) mp[s] = idx;
		for (int i = 1; i + s <= 2'000'000; i++) {
			if (mp[i] && mp[i] < idx) {
				if (!mp[i + s]) mp[i + s] = idx;
			}
		}
	}

	for (int i = 1; i <= 2'000'000; i++) {
		if (!mp[i]) {
			cout << i;
			return 0;
		}
	}
}