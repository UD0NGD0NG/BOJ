#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	unordered_map<char, stack<int>> alpha;
	unordered_map<char, int> idx;
	for (int i = 0; i < s.size(); i++) {
		alpha[s[i]].push(i);
	}

	for (char c : t) {
		if (alpha[c].empty()) {
			cout << 0;
			return 0;
		}

		idx[c] = alpha[c].top();
	}

	int ans = 0;
	bool zero = false;
	while (!zero) {
		bool skip = false;
		for (int i = 0; i < t.size() - 1; i++) {
			if (idx[t[i]] > idx[t[i + 1]]) {
				alpha[t[i]].pop();
				if (!zero) zero = alpha[t[i]].empty();

				if (!zero) idx[t[i]] = alpha[t[i]].top();

				skip = true;
				break;
			}
		}

		if (!skip) {
			for (int i = 0; i < t.size(); i++) {
				alpha[t[i]].pop();
				if (!zero) zero = alpha[t[i]].empty();

				if (!zero) idx[t[i]] = alpha[t[i]].top();
			}
			ans++;
		}
	}

	cout << ans;
}