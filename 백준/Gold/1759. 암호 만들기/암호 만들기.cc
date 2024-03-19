#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int l, c;
vector<char> password, letter;
set<char> vowel, consonant;

void backtracking(int idx) {
	if (password.size() == l) {
		int cnt_v = 0, cnt_c = 0; // 모음개수, 자음개수
		for (char x : password) {
			if (vowel.find(x) != vowel.end()) cnt_v++;
			if (consonant.find(x) != consonant.end()) cnt_c++;
		}

		if (cnt_v >= 1 && cnt_c >= 2) {
			for (char x : password)
				cout << x;
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < letter.size(); i++) {
		password.push_back(letter[i]);

		backtracking(i + 1); // 암호가 사전식으로 구성되기 위함

		password.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> c;

	while (c--) {
		char alphabet; cin >> alphabet;

		letter.push_back(alphabet);

		if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u') {
			vowel.insert(alphabet);
		}
		else {
			consonant.insert(alphabet);
		}
	}

	sort(letter.begin(), letter.end());

	backtracking(0);
}