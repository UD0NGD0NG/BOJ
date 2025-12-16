#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		list<char> ans; string L; auto cursor = ans.begin();
		cin >> L;
		for (char c : L) {
			if (c == '<') {
				cursor == ans.begin() ? cursor : cursor--;
			}
			else if (c == '>') {
				cursor == ans.end() ? cursor : cursor++;
			}
			else if (c == '-') {
				if (cursor != ans.begin()) {
					cursor = ans.erase(--cursor);
				}
			}
			else {
				cursor = ans.insert(cursor, c);
				cursor++;
			}
		}

		for (char c : ans) cout << c;
		cout << '\n';
	}
}