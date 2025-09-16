#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		
		int len = s.size();
		for (int i = 0; i < len; i++)
			if (s[i] == '6') s[i] = '9';
		
		sort(s.begin(), s.end());

		long long a = 0, b = 0;
		for (int i = len - 1; i >= 0; i--) {
			if (a >= b) {
				b = b * 10 + s[i] - 48;
			}
			else {
				a = a * 10 + s[i] - 48;
			}
		}

		cout << a * b << '\n';
	}
}