#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	return get<2>(t1) < get<2>(t2);
}

int Find(vector<int>& uf, int node) {
	if (uf[node] == node) return node;

	int root = Find(uf, uf[node]);
	uf[node] = root;
	return root;
}

void Union(vector<int>& uf, int node1, int node2) {
	uf[Find(uf, node1)] = Find(uf, node2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<int> uf(n + 1); for (int i = 1; i <= n; i++) uf[i] = i;

	vector<tuple<int, int, int>> road; // A번 집, B번 집, 길의 유지비
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		road.push_back(make_tuple(a, b, c));
	}
	sort(road.begin(), road.end(), comp); // 길의 유지비가 낮은 순서로 정렬

	int sum = 0; // mst의 모든 간선의 합 저장
	vector<int> mst;
	for (tuple<int, int, int> x : road) {
		if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) {
			mst.push_back(get<2>(x));
			sum += get<2>(x);
			Union(uf, get<0>(x), get<1>(x));
		}
	}

	sort(mst.begin(), mst.end()); // mst를 비용 오름차순으로 저장

	cout << sum - mst.back(); // 가장 비싼 간선 삭제(마을을 2개로 분리)
}