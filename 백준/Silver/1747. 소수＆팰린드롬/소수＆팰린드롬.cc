#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool pal(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<bool> prime(1'003'005, true); prime[1] = false;
	for (int i = 2; i <= sqrt(1'003'005); i++) {
		for (int j = 2; j * i < 1'003'005; j++) {
			prime[i * j] = false;
		}
	}

	int N; cin >> N;
	for (int i = N; i < 1'003'005; i++) {
		if (prime[i] && pal(to_string(i))) {
			cout << i;
			return 0;
		}
	}
}