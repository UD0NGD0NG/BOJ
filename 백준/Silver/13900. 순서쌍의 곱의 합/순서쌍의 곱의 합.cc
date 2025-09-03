#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<ll> sum(1, 0), num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum.push_back(sum.back() + num[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += num[i] * (sum.back() - sum[i + 1]);
	}

	cout << ans;
}