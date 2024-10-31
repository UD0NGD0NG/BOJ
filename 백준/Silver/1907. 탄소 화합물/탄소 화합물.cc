#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	map<char, int> m1, m2, m3;

	string s; cin >> s;

	auto target = &m1;
	for (int i = 1; i < s.size(); i++) {
		if ('2' <= s[i] && s[i] <= '9') {
			(*target)[s[i - 1]] += s[i] - 48;
		}
		else {
			(*target)[s[i - 1]]++;
		}

		if (s[i] == '+') {
			target = &m2;
		}
		else if (s[i] == '=') {
			target = &m3;
		}
	}
	
	if (s[s.size() - 1] < '2' || s[s.size() - 1] > '9') {
		m3[s[s.size() - 1]]++;
	}

	for (int x1 = 1; x1 <= 10; x1++) {
		for (int x2 = 1; x2 <= 10; x2++) {
			for (int x3 = 1; x3 <= 10; x3++) {
				if (m1['C'] * x1 + m2['C'] * x2 == m3['C'] * x3 && m1['H'] * x1 + m2['H'] * x2 == m3['H'] * x3 && m1['O'] * x1 + m2['O'] * x2 == m3['O'] * x3) {
					cout << x1 << ' ' << x2 << ' ' << x3;
					return 0;
				}
			}
		}
	}
}