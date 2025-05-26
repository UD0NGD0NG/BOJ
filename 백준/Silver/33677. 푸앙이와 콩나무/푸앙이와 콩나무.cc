#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ull = unsigned long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<pair<ull, ull>> Min(n + 3, { n, n }); Min[1] = { 1, 1 };
	queue<ull> ready; ready.push(1);

	while (!ready.empty()) {
		ull cur = ready.front();
		ready.pop();

		if (cur + 1 <= n && Min[cur].first + 1 < Min[cur + 1].first) {
			Min[cur + 1].first = Min[cur].first + 1;
			Min[cur + 1].second = Min[cur].second + 1;
			ready.push(cur + 1);
		}
		else if (cur + 1 <= n && Min[cur].first + 1 == Min[cur + 1].first) {
			if (Min[cur].second + 1 < Min[cur + 1].second) {
				Min[cur + 1].second = Min[cur].second + 1;
				ready.push(cur + 1);
			}
		}

		if (cur * 3 <= n && Min[cur].first + 1< Min[cur * 3].first) {
			Min[cur * 3].first = Min[cur].first + 1;
			Min[cur * 3].second = Min[cur].second + 3;
			ready.push(cur * 3);
		}
		else if (cur * 3 <= n && Min[cur].first + 1 == Min[cur * 3].first) {
			if (Min[cur].second + 3 < Min[cur * 3].second) {
				Min[cur * 3].second = Min[cur].second + 3;
				ready.push(cur * 3);
			}
		}

		if (cur * cur <= n && Min[cur].first + 1 < Min[cur * cur].first) {
			Min[cur * cur].first = Min[cur].first + 1;
			Min[cur * cur].second = Min[cur].second + 5;
			ready.push(cur * cur);
		}
		else if (cur * cur <= n && Min[cur].first + 1 == Min[cur + 1].first) {
			if (Min[cur].second + 5 < Min[cur * cur].second) {
				Min[cur * cur].second = Min[cur].second + 5;
				ready.push(cur * cur);
			}
		}
	}

	cout << Min[n].first << ' ' << Min[n].second;
}