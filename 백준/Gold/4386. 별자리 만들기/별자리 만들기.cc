#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // sort
#include <cmath> // sqrt
#include <iomanip> // fixed, setprecision
using namespace std;

bool cmp(tuple<int, int, double> a, tuple<int, int, double> b) { //  그래프를 가중치 오름차순으로 정렬하기 위한 함수
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

double dist(pair<double, double> a, pair<double, double> b) { // 두 좌표사이의 거리를 구하는 함수
	double x = abs(a.first - b.first);
	double y = abs(a.second - b.second);
	return sqrt(x * x + y * y);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<tuple<int, int, double>> edge;
	vector<pair<double, double>> star;
	int n, i, j;
	double x, y, cost = 0;
	cin >> n;
	vector<int> uf(n); for (int i = 0; i < n; i++) uf[i] = i;

	while (n--) {
		cin >> x >> y;
		star.push_back(make_pair(x, y));
	}

	for (i = 0; i < star.size() - 1; i++) {
		for (j = i + 1; j < star.size(); j++) {
			edge.push_back(make_tuple(i, j, dist(star[i], star[j]))); // 두 별을 잇는 간선을 모두 저장
		}
	}

	sort(edge.begin(), edge.end(), cmp);

	for (tuple<int, int, double> x : edge) {
		if (Find(uf, get<0>(x)) != Find(uf, get<1>(x))) {
			Union(uf, get<0>(x), get<1>(x));
			cost += get<2>(x);
		}
	}

	cout << fixed << setprecision(2) << cost;
}