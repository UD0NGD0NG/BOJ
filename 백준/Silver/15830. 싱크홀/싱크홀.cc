#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long v, w, d; cin >> v >> w >> d;

	long long ans = 0;
	while (80 * w * w * pow(25, ans) - 80 * w * w * pow(16, ans) < 9 * d * v * v * pow(16, ans)) {
		ans++;
	}

	cout << ans - 1;
}