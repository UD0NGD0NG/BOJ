#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

set<string> can;

struct cmp {
	bool operator()(const pair<string, string>& lhs, const pair<string, string>& rhs) {
		if (lhs.first == rhs.first) {
			if ((can.find(lhs.second) != can.end() && can.find(rhs.second) != can.end()) || (can.find(lhs.second) == can.end() && can.find(rhs.second) == can.end())) {
				return lhs.second > rhs.second;
			}
			else if (can.find(lhs.second) == can.end() && can.find(rhs.second) != can.end()) {
				return true;
			}
			else {
				return false;
			}
		}
		return lhs.first > rhs.first;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<pair<string, string>> v;
	priority_queue<pair<string, string>, vector<pair<string, string>>, cmp> pq;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		string name = "", ext = "";

		bool b = true;
		for (char c : s) {
			if (c == '.') {
				b = false;
				continue;
			}
			if (b) name += c;
			else ext += c;
		}

		v.push_back({ name, ext });
	}

	while (m--) {
		string cand; cin >> cand;
		can.insert(cand);
	}

	for (auto a : v) {
		pq.push(a);
	}

	while (!pq.empty()) {
		cout << pq.top().first << '.' << pq.top().second << '\n';
		pq.pop();
	}
}