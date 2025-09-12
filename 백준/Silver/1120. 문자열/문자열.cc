#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
	int ans = a.size();
	for (int i = 0; i <= b.size() - a.size(); i++) {
		int cur = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[i + j]) cur++;
		}

		ans = ans < cur ? ans : cur;
	}

	cout << ans;
}