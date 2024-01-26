#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
using namespace std;

bool can(string a, set<char>& s) { // 리모컨에 누를 숫자중 고장난 숫자가 있는지 판정
	for (int i = 0; i < a.size(); i++)
		if (s.find(a[i]) == s.end())
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	set<char> s = { '0','1','2','3','4','5','6','7','8','9' };
	int n, m, w1, w2, w3, tmp, flag = 1;
	char c;
	cin >> n >> m;
	while (m--) {
		cin >> c; // 고장난 버튼
		s.erase(c);
	}
	w1 = abs(100 - n); // 100부터 일일이 + or - 버튼 누르기
	tmp = n;
	if ((s.size() == 1 && *s.begin() == '0') || s.size() == 0) // 버튼이 0만 있거나 아무것도 없으면
		w2 = INT_MAX; // way2불가능
	else {
		while (!can(to_string(tmp), s)) {
			if (tmp == 999900) // 100부터 일일이 누르는 것보다 눌러야하는 버튼수가 많아지는 경우
				break;
			tmp++;
		}
		w2 = to_string(tmp).size() + tmp - n; // 누를 수 있는 버튼 조합으로 수가 만들어졌다면 w2 = 해당 수를 입력하기 위한 버튼수 + -를 누르는 횟수
	}
	tmp = n;
	if (s.size() == 0) // 버튼이 없으면
		w3 = INT_MAX; //way3 불가능
	else {
		while (!can(to_string(tmp), s)) {
			if (tmp == 0) { // 0에 도달했을 때
				if (s.find('0') != s.end()) { // 버튼에 0이 있으면
					w3 = n + 1; // 0에서 일일이 + 버튼 누르기
					flag = 0;
					break;
				}
				else { // 버튼에 0이 없으면
					w3 = INT_MAX; // way3불가
					flag = 0;
					break;
				}
			}
			tmp--; // n이 0인경우 tmp--가 if문 위에 있을경우 무한루프 발생
		}
		if (flag) // 0보다 큰 수가 누를 수 있는 버튼 조합으로 수가 만들어진 경우
			w3 = to_string(tmp).size() + n - tmp; // w3 = 해당 수를 입력하기 위한 버튼수 + +를 누르는 횟수
	}
	cout << min(w1, min(w2, w3));
}