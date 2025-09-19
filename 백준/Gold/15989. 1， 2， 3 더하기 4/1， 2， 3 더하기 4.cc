#include <iostream>
using namespace std;

int main() {
	long long lastIsOne[10'005], lastIsTwo[10'005], lastIsThree[10'005];
	lastIsOne[1] = 1, lastIsTwo[1] = 0, lastIsThree[1] = 0;
	lastIsOne[2] = 1, lastIsTwo[2] = 1, lastIsThree[2] = 0;
	lastIsOne[3] = 1, lastIsTwo[3] = 1, lastIsThree[3] = 1;

	for (int i = 4; i <= 10'000; i++) {
		lastIsOne[i] = lastIsOne[i - 1];
		lastIsTwo[i] = lastIsOne[i - 2] + lastIsTwo[i - 2];
		lastIsThree[i] = lastIsOne[i - 3] + lastIsTwo[i - 3] + lastIsThree[i - 3];
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << lastIsOne[n] + lastIsTwo[n] + lastIsThree[n] << '\n';
	}
}