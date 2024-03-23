#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
using tiii = tuple<int, int, int>;
using tiid = tuple<int, int, double>;

bool cmp(tiid a, tiid b) {
	return get<2>(a) < get<2>(b);
}

int Find(vector<int>& uf, int node) {
	if (uf[node] == node) return node;

	int root = Find(uf, uf[node]);
	uf[node] = root;
	return root;
}

void Union(vector<int>& uf, int node1, int node2) {
	int root1 = Find(uf, node1), root2 = Find(uf, node2);

	uf[root1] = root2;
}

double dist(tiii a, tiii b) {
	ll x = abs(get<0>(a) - get<0>(b)), y = abs(get<1>(a) - get<1>(b));
	return sqrt(x * x + y * y);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<int> uf(n + 1); for (int i = 1; i <= n; i++) uf[i] = i;

	vector<tiii> god; // x, y, idx
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		god.push_back(make_tuple(x, y, i));
	}

	while (m--) {
		int node1, node2; cin >> node1 >> node2;
		Union(uf, node1, node2);
	}

	vector<tiid> path; // 우주신1의 번호, 우주신2의 번호, 두 신을 잇는 통로의 길이
	for (int i = 0; i < god.size(); i++) {
		for (int j = i + 1; j < god.size(); j++) {
			path.push_back(make_tuple(get<2>(god[i]), get<2>(god[j]), dist(god[i], god[j])));
		}
	}

	sort(path.begin(), path.end(), cmp); // 통로 길이를 기준으로 오름차순 정렬

	double ans = 0;
	for (tiid x : path) {
		if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) { // 아직 연결되어있지 않다면
			ans += get<2>(x); // 통로 추가 후
			Union(uf, get<0>(x), get<1>(x)); // 두 우주신 연결
		}
	}

	cout << fixed << setprecision(2) << ans; // 소수점 둘째 자리까지 반올림하여 출력
}