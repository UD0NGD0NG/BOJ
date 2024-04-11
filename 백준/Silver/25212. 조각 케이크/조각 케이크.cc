#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int GCD(int a, int b) {
	if (b == 0) return a;

	return GCD(b, a % b);
}

int n, cnt = 0;
vector<pii> v(10); // first: 분자, second: 분모
pii sum = make_pair(0, 0);

pii Sum(pii a, pii b) {
	if (!(a.first || a.second)) return b; // a가 0/0일때는 b를 return

	int num = a.first * b.second + a.second * b.first;
	int deno = a.second * b.second;

	int gcd = GCD(num, deno);

	num /= gcd; deno /= gcd; // 약분

	return make_pair(num, deno); // 두 분수의 합 return
}


void backtracking(int idx) {
	if (99.0 / 100.0 <= (double)(sum.first) / sum.second && (double)(sum.first) / sum.second <= 101.0 / 100.0) cnt++; // 케이크 한 판으로 만들 수 있는 경우

	for (int i = idx; i < n; i++) {
		pii tmp = sum;
		sum = Sum(sum, v[i]); // 현재 판단중인 케이크 선택

		backtracking(i + 1); // 다음 케이크 판단

		sum = tmp; // 현재 케이크 선택 취소
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int c;  cin >> c;
		v[i] = make_pair(1, c);
	}

	backtracking(0); // 첫번째 케이크부터 판단

	cout << cnt;
}