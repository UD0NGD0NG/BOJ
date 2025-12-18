#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<bool> prime(1005, true);
	for (int i = 2; i <= sqrt(1005); i++) {
		for (int j = 2; j * i < 1005; j++) {
			prime[i * j] = false;
		}
	}

	int A, B, C, D; cin >> A >> B >> C >> D;

	int yt = 0, yj = 0, both = 0;
	for (int i = A; i <= B; i++) if (prime[i]) yt++;
	for (int i = C; i <= D; i++) if (prime[i]) yj++;
	for (int i = C; i <= B; i++) if (prime[i]) both++;

	yt + both % 2 > yj ? cout << "yt" : cout << "yj";
}