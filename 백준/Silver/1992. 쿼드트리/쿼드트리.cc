#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> v;

void Solve(int iS, int iE, int jS, int jE) {
	if (iS == iE || jS == jE) return;

	bool flag = true;
	for (int i = iS; i < iE; i++) {
		for (int j = jS; j < jE; j++) {
			if (flag) flag = (v[iS][jS] == v[i][j]);
		}
	}
	if (flag) cout << v[iS][jS];
	else {
		cout << '(';
		int iN = (iS + iE) / 2, jN = (jS + jE) / 2;
		Solve(iS, iN, jS, jN);
		Solve(iS, iN, jN, jE);
		Solve(iN, iE, jS, jN);
		Solve(iN, iE, jN, jE);
		cout << ')';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	v.resize(n, vector<char>(n));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];

	Solve(0, n, 0, n);
}