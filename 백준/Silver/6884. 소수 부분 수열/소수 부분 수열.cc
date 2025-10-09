#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
	if (x < 2) return false;

	for (int i = 2; i * i <= x; i++) {
		if (!(x % i)) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, cnt = 0; cin >> n;
		vector<int> v(1, 0), ans;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(v.back() + x);
		}
		
		for (int i = 2; i <= n; i++) {
			if (cnt) break;
			for (int j = i; j <= n; j++) {
				if (cnt) break;
				if (isPrime(v[j] - v[j - i])) {
					cnt = i;
					for (int k = i; k > 0; k--) {
						ans.push_back(v[j - k + 1] - v[j - k]);
					}
				}
			}
		}

		if (cnt) {
			cout << "Shortest primed subsequence is length " << cnt << ": ";
			for (int i : ans) cout << i << ' ';
			cout << '\n';
		}
		else {
			cout << "This sequence is anti-primed.\n";
		}
	}
}