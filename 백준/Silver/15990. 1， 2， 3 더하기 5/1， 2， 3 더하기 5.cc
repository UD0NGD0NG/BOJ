#include <iostream>
using namespace std;

const int MOD = 1'000'000'009;

int main() {
	long long lastIsOne[100'005], lastIsTwo[100'005], lastIsThree[100'005];
	lastIsOne[1] = 1, lastIsTwo[1] = 0, lastIsThree[1] = 0;
	lastIsOne[2] = 0, lastIsTwo[2] = 1, lastIsThree[2] = 0;
	lastIsOne[3] = 1, lastIsTwo[3] = 1, lastIsThree[3] = 1;

	for (int i = 4; i <= 100'000; i++) {
		lastIsOne[i] = (lastIsTwo[i - 1] + lastIsThree[i - 1]) % MOD;
		lastIsTwo[i] = (lastIsOne[i - 2] + lastIsThree[i - 2]) % MOD;
		lastIsThree[i] = (lastIsOne[i - 3] + lastIsTwo[i - 3]) % MOD;
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (lastIsOne[n] + lastIsTwo[n] + lastIsThree[n]) % MOD << '\n';
	}
}