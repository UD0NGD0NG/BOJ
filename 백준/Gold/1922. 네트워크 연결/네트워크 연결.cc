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

void Union(vector<int>& uf, int node1, int node2) {
	uf[Find(uf, node1)] = Find(uf, node2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, a, b, c, cost = 0;
	cin >> n >> m;
	vector<tuple<int, int, int>> edge; // <0>: 컴퓨터1, <1>: 컴퓨터2, <2>: 연결 비용
	vector<int> uf(n + 1); for (int i = 1; i <= n; i++) uf[i] = i;

	while (m--) {
		cin >> a >> b >> c; // a == b 인 경우 line.38에 걸러지므로 따로 예외처리 X
		edge.push_back(make_tuple(a, b, c));
	}

	sort(edge.begin(), edge.end(), cmp);

	for (tuple<int, int, int> x : edge) {
		if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) {
			Union(uf, get<0>(x), get<1>(x));
			cost += get<2>(x);
		}
	}

	cout << cost;
}