#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // min()
#include <stdlib.h> // abs()
using namespace std;

const int INF = 122500; // 50X50격자에서 모서리만 치킨집이고 나머지가 모두 집인 경우의 거리(최악의 경우)
vector <pair<int, int>> tmp; // 서로다른 치킨집을 m개 저장
int ans = INF;

void backtracking(vector<pair<int, int>>& chicken, vector<pair<int, int>>& home, int m, int idx) {
	if (tmp.size() == m) { // m개 저장되면 거리를 구한 후 최솟값인지 판정
		int dist = 0; // 거리합 구하기
		for (pair<int, int> x : home) {
			set<int> s;
			for (pair<int, int> y : tmp) {
				s.insert(abs(x.first - y.first) + abs(x.second - y.second)); // 하나의 집으로 부터 모든 치킨집의 거리를 저장
			}

			dist += *s.begin(); // 그 중 최솟값을 저장
		}

		ans = min(ans, dist); // 최솟값 판정
	}
	for (int i = idx; i < chicken.size(); i++) {
		tmp.push_back(chicken[i]);
		backtracking(chicken, home, m, i + 1); // 치킨집이 중복되지 않도록 저장하기 위함
		tmp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	
	vector<pair<int, int>> chicken; // 치킨집의 위치를 저장
	vector<pair<int, int>> home; // 집의 위치를 저장
	vector<vector<char>> v(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];

			if (v[i][j] == '1') {
				home.push_back(make_pair(i, j));
			}
			else if (v[i][j] == '2') {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	backtracking(chicken, home, m, 0);

	cout << ans;
}