#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b;

	if (a <= b || a > b * 2) {
		cout << "NO";
	}
	else {
		cout << "YES\n" << a - b << '\n';

		for (int i = 1; i < a - b; i++) {
			cout << "aba\n";
		}

		cout << "a";
		for (int i = 0; i < b - (a - b - 1); i++) {
			cout << "ba";
		}
	}
}