#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<string, int> mp;
	vector<string> v;
	int n, i, j, cnt = 0;
	string c;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> c;
		mp[c] = i;
	}
	for (i = 0; i < n; i++) {
		cin >> c;
		v.push_back(c);
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (mp[v[i]] > mp[v[j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}