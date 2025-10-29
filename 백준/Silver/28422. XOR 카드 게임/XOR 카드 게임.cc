#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int score(int i) {
	int cnt = 0;

	while (i) {
		cnt += i % 2;
		i /= 2;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans = 0, n; cin >> n;
	vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
	
	vector<int> dp(n);
	dp[0] = 0;
	if (n > 1) {
		dp[1] = score(v[0] ^ v[1]);
	}
	if (n > 2) {
		dp[2] = score(v[0] ^ v[1] ^ v[2]);
	}
	if (n > 3) {
		dp[3] = dp[1] + score(v[2] ^ v[3]);
	}
	if (n > 4) {
		for (int i = 4; i < n; i++) {
			dp[i] = max(dp[i - 2] + score(v[i] ^ v[i - 1]), dp[i - 3] + score(v[i] ^ v[i - 1] ^ v[i - 2]));
		}
	}

	cout << dp[n - 1];
}