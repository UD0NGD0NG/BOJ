#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, d, p, i, j, ans = 0;
	cin >> n >> m;
	
	vector<pair<int, int>> chap(m);
	vector<vector<int>> book(m, vector<int>(n + 1, -1)); // m: 챕터의 수, n: 읽은 기간, 값: 읽은 페이지(최대로)
	
	for (i = 0; i < m; i++) {
		cin >> d >> p;
		chap[i] = make_pair(d, p);
	}
	
	book[0][0] = 0;
	if (chap[0].first <= n) // 해당 챕터를 읽는데 걸리는 기간이 남은 기간보다 큰 경우 방지
		book[0][chap[0].first] = chap[0].second;
	
	for (i = 1; i < m; i++) {
		for (j = 0; j <= n; j++) {
			if (j >= chap[i].first && book[i - 1][j - chap[i].first] != -1)
				book[i][j] = max(book[i - 1][j], book[i - 1][j - chap[i].first] + chap[i].second);
			else
				book[i][j] = book[i - 1][j];
		}
	}

	for (i = 0; i <= n; i++)
		if (ans < book[m - 1][i])
			ans = book[m - 1][i];
	
	cout << ans;
}