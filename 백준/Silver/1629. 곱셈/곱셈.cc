#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

unordered_map<ll, ll> dp;
ll a, b, c;

void Solve(ll n) {
	if (dp[n]) return;
	if (n % 2) {
		ll l = n / 2, r = l + 1;
		if (!dp[l]) Solve(l);
		if (!dp[r]) Solve(r);
		
		dp[n] = (dp[l] * dp[r]) % c;
	}
	else {
		if (!dp[n / 2]) Solve(n / 2);
		
		dp[n] = (dp[n / 2] * dp[n / 2]) % c;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;

	dp[0] = 1, dp[1] = a % c;
	if (!(a % c)) {
		cout << 0;
		return 0;
	}
	
	Solve(b);
	cout << dp[b];
}