#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using tiii = tuple<int, int, int>;

bool cmp(tiii a, tiii b) {
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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;

	while (m && n) {
		vector<int> uf(m); for (int i = 0; i < m; i++) uf[i] = i;

		vector<tiii> road; // 집1, 집2, 거리
		int origin_cost = 0; // 모든 길에 가로등이 켜질 경우의 비용
		while (n--) {
			int x, y, z; cin >> x >> y >> z;
			road.push_back(make_tuple(x, y, z));
			origin_cost += z;
		}

		sort(road.begin(), road.end(), cmp); // 비용을 기준으로 오름차순 정렬

		int total_cost = 0; // 최소한의 비용 저장
		for (tiii x : road) {
			if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) { // 두 집 사이에 가로등이 켜진 길이 없다면
				total_cost += get<2>(x); // 가로등을 추가
				Union(uf, get<0>(x), get<1>(x));
			}
		}

		cout << origin_cost - total_cost << '\n'; // 아낀 비용 출력

		cin >> m >> n;
	}
}