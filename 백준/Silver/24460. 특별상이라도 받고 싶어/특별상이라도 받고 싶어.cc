#include <iostream>
#include <vector>
#include <set>
using namespace std;
using V = vector<int>;
using M = vector<V>;


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	
	M m(n, V(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	while (n != 1) {
		n /= 2;
		M tmp(n, V(n));
		set<int> s;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				s.insert(m[i * 2][j * 2]);
				s.insert(m[i * 2 + 1][j * 2]);
				s.insert(m[i * 2][j * 2 + 1]);
				s.insert(m[i * 2 + 1][j * 2 + 1]);

				tmp[i][j] = *(++s.begin());
				s.clear();
			}
		}

		m = tmp;
	}
	
	cout << m[0][0];
}