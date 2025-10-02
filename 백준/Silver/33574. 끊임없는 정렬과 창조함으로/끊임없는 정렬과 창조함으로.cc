#include <iostream>
#include <list>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	list<int> s;
	int q; cin >> q;
	while (q--) {
		int cmd; cin >> cmd;
		if (cmd - 1) {
			int x, t; cin >> x >> t;
			auto it = s.begin();
			while (x--) it++;
			s.insert(it, t);
		}
		else {
			int x; cin >> x;
			if (x - 1) {
				s.sort(greater<int>());
			}
			else {
				s.sort();
			}
		}
	}

	cout << s.size() << '\n';
	for (int i : s) cout << i << ' ';
}