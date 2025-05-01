#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	double v, w, d; cin >> v >> w >> d;

	int cur = 0, ans = 0;
	while (cur < d) {
		cur += 5 * (w / v) * (w / v);

		if (cur < d) {
			ans++;
			v *= 0.8;
		}
	}

	cout << ans;
}