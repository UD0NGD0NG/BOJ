#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) { // 그래프를 가중치 오름차순으로 정렬하기 위한 함수
	return get<2>(a) < get<2>(b);
}

int Find(vector<int>& uf, int node) {
	if (uf[node] == node) // node -> root
		return node;
	int root = Find(uf, uf[node]);
	uf[node] = root;
	return root;
}

void Union(vector<int>& uf, int a, int b) {
	uf[Find(uf, a)] = Find(uf, b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v, e, a, b, c, weight = 0;
	cin >> v >> e;
	vector<tuple<int, int, int>> edge; // <0>: 정점1, <1>: 정점2, <2>: 가중치
	vector<int> uf(v + 1); for (int i = 1; i <= v; i++) uf[i] = i;

	while (e--) {
		cin >> a >> b >> c;
		edge.push_back(make_tuple(a, b, c));
	}

	sort(edge.begin(), edge.end(), cmp);

	for (tuple<int, int, int> x : edge) {
		if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) { // 그래프의 사이클이 생기는 것을 방지
			Union(uf, get<0>(x), get<1>(x));
			weight += get<2>(x);
		}
	}

	cout << weight;
}