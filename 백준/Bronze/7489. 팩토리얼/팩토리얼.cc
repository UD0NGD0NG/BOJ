#include <iostream>
#include <string>
using namespace std;

void maintain(int& n) {
	while (!(n % 10)) {
		n /= 10;
	}

	n %= 10000;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	/*int t = 1;*/

	while (t--) {
		int n; cin >> n;

		int ans = 1;
		for (int i = 1; i <= n; i++) {
			ans *= i;
			maintain(ans);
		}

		cout << ans % 10 << '\n';
	}
}