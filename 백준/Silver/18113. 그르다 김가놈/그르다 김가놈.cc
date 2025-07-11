#include <iostream>
#include <vector>
using namespace std;

vector<int> l;
int n, k, m, p = -1;

bool isPossible(int mid) {
	int cnt = 0;
	for (int i : l) {
		cnt += i / mid;
	}

	return cnt >= m;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> m;

	l.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];

		if (l[i] >= 2 * k) {
			l[i] -= 2 * k;
		}
		else if (l[i] > k) {
			l[i] -= k;
		}
		else {
			l[i] = 0;
		}
	}

	int left = 1, right = 1'000'000'000;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(mid)) {
			p = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << p;
}