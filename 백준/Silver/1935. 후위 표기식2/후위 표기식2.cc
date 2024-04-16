#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

double cal(double left, double right, char c) {
	if (c == '+') return left + right;
	else if (c == '-') return left - right;
	else if (c == '*') return left * right;
	else return left / right;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	double arr[26];

	string s; cin >> s;

	for (int i = 0; i < n; i++) cin >> arr[i];

	stack<double> st;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			st.push(arr[s[i] - 'A']);
		}
		else {
			double right = st.top(); st.pop();
			double left = st.top(); st.pop();
			st.push(cal(left, right, s[i]));
		}
	}

	cout << fixed << setprecision(2) << st.top();
}