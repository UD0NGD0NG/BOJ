#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	unordered_map<int, multiset<int>> mp1;
	unordered_map<int, multiset<int>> mp2;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v[i] = { x, y };
		mp1[x].insert(y);
		mp2[y].insert(x);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)(mp1[v[i].first].size() - 1) * (mp2[v[i].second].size() - 1);
	}

	cout << ans;
}