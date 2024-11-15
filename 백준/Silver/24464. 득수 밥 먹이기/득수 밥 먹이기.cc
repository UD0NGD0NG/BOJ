#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v(5);

	ll mod = 1'000'000'007;

	int n; cin >> n;
	vector<vector<ll>> c1(3, vector<ll>(n, 0)); c1[0][0] = 1;
	vector<vector<ll>> c2(3, vector<ll>(n, 0)); c2[1][0] = 2;
	vector<vector<ll>> c3(3, vector<ll>(n, 0)); c3[2][0] = 2;

	for (int i = 1; i < n; i++) {
		c1[0][i] = (c1[1][i - 1] + c1[2][i - 1]) % mod;
		c1[1][i] = (c1[0][i - 1] * 2 + c1[1][i - 1] + c1[2][i - 1]) % mod;
		c1[2][i] = (c1[0][i - 1] * 2 + c1[1][i - 1]) % mod;

		c2[0][i] = (c2[1][i - 1] + c2[2][i - 1]) % mod;
		c2[1][i] = (c2[0][i - 1] * 2 + c2[1][i - 1] + c2[2][i - 1]) % mod;
		c2[2][i] = (c2[0][i - 1] * 2 + c2[1][i - 1]) % mod;

		c3[0][i] = (c3[1][i - 1] + c3[2][i - 1]) % mod;
		c3[1][i] = (c3[0][i - 1] * 2 + c3[1][i - 1] + c3[2][i - 1]) % mod;
		c3[2][i] = (c3[0][i - 1] * 2 + c3[1][i - 1]) % mod;
	}

	cout << (c1[0][n - 1] + c1[1][n - 1] + c1[2][n - 1] + c2[0][n - 1] + c2[1][n - 1] + c2[2][n - 1] + c3[0][n - 1] + c3[1][n - 1] + c3[2][n - 1]) % mod;
}