#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int memo[31] = {}; memo[0] = 1;

	for (int i = 2; i <= 30; i += 2) {
		for (int j = 0; j <= i - 2; j += 2) {
			memo[i] += memo[j] * 2;
		}
		memo[i] += memo[i - 2];
	}

	int n; cin >> n; cout << memo[n];

	// n이 홀수면 0, 짝수인 경우에는 [n - 2] * 3 + [n - 4] * 2 + ... [0] * 2
}