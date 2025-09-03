#include <iostream>
#include <cmath>
#include <set>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x; cin >> x; x++;

	set<ll> s;
	for (int i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) {
			s.insert(i); s.insert(x / i);
		}
	}

	s.erase(x);

	for (ll l : s) cout << l << ' ';
}