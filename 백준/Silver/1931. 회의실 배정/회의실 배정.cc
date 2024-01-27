#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first; // 반대로 정렬 시 시작과 동시에 끝나는 경우가 우선시 되기에 최적의 조건이 아니게됨
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int f, cnt = 1, n, s, e, i;
	vector<pair<int, int>> v;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
	sort(v.begin(), v.end(), cmp);
	f = v[0].second; // 끝나는 시간을 기준으로
	for (i = 1; i < n; i++) {
		if (f <= v[i].first) { // 시작시간보다 끝난시간이 동일하거나 빠른경우 회의 진행
			f = v[i].second;
			cnt++;
		}
	}
	cout << cnt;
}