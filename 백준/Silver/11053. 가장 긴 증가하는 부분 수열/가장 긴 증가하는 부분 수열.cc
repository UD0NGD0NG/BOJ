#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, A[1'005]{}, DP[1'005]{}; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	DP[0] = 1;
	for (int i = 1; i < N; i++) {
		int cur = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				cur = max(cur, DP[j] + 1);
			}
		}
		DP[i] = cur;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, DP[i]);
	}

	cout << ans;
}