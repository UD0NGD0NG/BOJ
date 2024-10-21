#include <iostream>
using namespace std;
using ll = long long;

void maintain(ll& n) {
	while (!(n % 10)) {
		n /= 10;
	}

	n %= 1000000;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		maintain(ans);
	}

	cout << ans % 10;
}