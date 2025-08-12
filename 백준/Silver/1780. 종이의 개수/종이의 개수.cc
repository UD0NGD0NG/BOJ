#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int ans[3];

void Solve(int iS, int iE, int jS, int jE) {
	if (iS == iE || jS == jE) return;

	bool flag = true;
	for (int i = iS; i < iE; i++) {
		for (int j = jS; j < jE; j++) {
			if (flag) flag = (v[iS][jS] == v[i][j]);
		}
	}
	if (flag) ans[v[iS][jS] + 1]++;
	else {
		int iT = (iE - iS) / 3, jT = (jE - jS) / 3;
		Solve(iS + iT * 0, iS + iT * 1, jS + jT * 0, jS + jT * 1);
		Solve(iS + iT * 0, iS + iT * 1, jS + jT * 1, jS + jT * 2);
		Solve(iS + iT * 0, iS + iT * 1, jS + jT * 2, jS + jT * 3);
		Solve(iS + iT * 1, iS + iT * 2, jS + jT * 0, jS + jT * 1);
		Solve(iS + iT * 1, iS + iT * 2, jS + jT * 1, jS + jT * 2);
		Solve(iS + iT * 1, iS + iT * 2, jS + jT * 2, jS + jT * 3);
		Solve(iS + iT * 2, iS + iT * 3, jS + jT * 0, jS + jT * 1);
		Solve(iS + iT * 2, iS + iT * 3, jS + jT * 1, jS + jT * 2);
		Solve(iS + iT * 2, iS + iT * 3, jS + jT * 2, jS + jT * 3);

	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];

	Solve(0, n, 0, n);

	for (int i = 0; i < 3; i++) cout << ans[i] << '\n';
}