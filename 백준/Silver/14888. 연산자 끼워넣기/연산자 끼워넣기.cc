#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> ans = make_pair(-1000000000, 1000000000);
vector<int> num;
vector<int> oper_list(4); // 0 == +, 1 == -, 2 == x, 3 == /
vector<int> oper;

int calc(int a, int b, int c) {
	if (c == 0) {
		return a + b;
	}
	else if (c == 1) {
		return a - b;
	}
	else if (c == 2) {
		return a * b;
	}
	else if (c == 3) {
		return a / b;
	}
}

void backtracking() {
	if (oper.size() == n - 1) {
		int sum = num[0];

		for (int i = 0; i < n - 1; i++) {
			sum = calc(sum, num[i + 1], oper[i]);
		}

		ans.first = max(ans.first, sum);
		ans.second = min(ans.second, sum);
		return;
	}

	vector<int> tmp = oper_list;
	for (int j = 0; j < 4; j++) {
		if (oper_list[j]) {
			oper.push_back(j);
			oper_list[j]--;
			backtracking();

			oper.pop_back();
			oper_list = tmp;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num.push_back(a);
	}

	for (int i = 0; i < 4; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			oper_list[i] = cnt;
		}
	}

	backtracking();

	cout << ans.first << '\n' << ans.second;
}