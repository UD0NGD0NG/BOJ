#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using tiii = tuple<int, int, int>;
using pti = pair<tiii, int>;

bool cmp(tiii a, tiii b) {
	return get<2>(a) < get<2>(b);
}

bool cmpx(pti a, pti b) {
	return get<0>(a.first) < get<0>(b.first);
}

bool cmpy(pti a, pti b) {
	return get<1>(a.first) < get<1>(b.first);
}

bool cmpz(pti a, pti b) {
	return get<2>(a.first) < get<2>(b.first);
}

int Costx(tiii a, tiii b) {
	return abs(get<0>(a) - get<0>(b));
}

int Costy(tiii a, tiii b) {
	return abs(get<1>(a) - get<1>(b));
}

int Costz(tiii a, tiii b) {
	return abs(get<2>(a) - get<2>(b));
}

int Find(vector<int>& uf, int node) {
	if (uf[node] == node)
		return node;
	int root = Find(uf, uf[node]);
	uf[node] = root;
	return root;
}

void Union(vector<int>& uf, int node1, int node2) {
	uf[Find(uf, node1)] = Find(uf, node2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<tiii> edge; // 터널 후보 저장(<행성1, 행성2, 비용>)
	vector<pti> planet; // 행성 정보 저장(<x좌표, y좌표, z좌표>, index)
	int n;  cin >> n; // 행성 개수
	vector<int> uf(n); for (int i = 0; i < n; i++) uf[i] = i;

	for (int i = 0; i < n; i++) {
		int x, y, z;  cin >> x >> y >> z; // 좌표
		planet.push_back(make_pair(make_tuple(x, y, z), i));
	}

	sort(planet.begin(), planet.end(), cmpx); // x좌표를 기준으로 행성 정렬
	for (int i = 1; i < n; i++) { // x좌표를 기준으로 인접한 행성사이의 터널 저장
		edge.push_back(make_tuple(planet[i - 1].second, planet[i].second, Costx(planet[i - 1].first, planet[i].first)));
	}

	sort(planet.begin(), planet.end(), cmpy); // y좌표를 기준으로 행성 정렬
	for (int i = 1; i < n; i++) { // y좌표를 기준으로 인접한 행성사이의 터널 저장
		edge.push_back(make_tuple(planet[i - 1].second, planet[i].second, Costy(planet[i - 1].first, planet[i].first)));
	}

	sort(planet.begin(), planet.end(), cmpz); // z좌표를 기준으로 행성 정렬
	for (int i = 1; i < n; i++) { // z좌표를 기준으로 인접한 행성사이의 터널 저장
		edge.push_back(make_tuple(planet[i - 1].second, planet[i].second, Costz(planet[i - 1].first, planet[i].first)));
	}


	sort(edge.begin(), edge.end(), cmp); // 비용을 기준으로 터널 후보 오름차순 정렬

	int cost = 0; // 총 비용 저장
	for (tiii x : edge) { // 비용이 낮은 터널부터
		if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) { // 두 행성이 이어져있지 않으면
			Union(uf, get<0>(x), get<1>(x)); // 이어주고
			cost += get<2>(x); // 총비용에 해당 터널의 비용 더해주기
		}
	}

	cout << cost;
}