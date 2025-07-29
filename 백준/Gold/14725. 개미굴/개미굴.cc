#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
using namespace std;

using node = tuple<string, string, int>;

map<node, set<node>> info;

void dfs(node cur) {
	for (int i = 0; i < get<2>(cur); i++) {
		cout << "--";
	}
	cout << get<1>(cur) << '\n';

	for (auto a : info[cur]) {
		dfs(a);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	set<node> start;

	int N; cin >> N;
	while (N--) {
		int k; cin >> k;
		node pre;
		for (int i = 0; i < k; i++) {
			string t; cin >> t;
			
			string floor = to_string(i);
			if (floor.size() == 1) floor = "0" + floor;

			node n = make_tuple(get<0>(pre) + floor + t, t, i);
			if (i) {
				info[pre].insert(n);
			}
			else {
				start.insert(n);
			}
			
			pre = n;
		}
	}

	for (node n : start) {
		dfs(n);
	}
}