#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> prime(2'000'005, false);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 2; i < sqrt(2'000'005); i++) {
		for (int j = 2; j * i < 2'000'000; j++) {
			prime[i * j] = true;
		}
	}

	int n, m; cin >> n >> m;
	vector<int> ans;
	for (int i = 1; i < 2'000'000 - (n - 1) * m; i++) {
		if (!prime[i]) continue;
		
		ans.push_back(i);
		while (ans.size() != n) {
			if (ans.back() + m > 2'000'000 || !prime[ans.back() + m]) {
				ans.clear();
				break;
			}
			else {
				ans.push_back(ans.back() + m);
			}
		}

		if (ans.size() == n) break;
	}

	if (ans.empty()) {
		cout << -1;
	}
	else {
		for (int i : ans) cout << i << ' ';
	}
}