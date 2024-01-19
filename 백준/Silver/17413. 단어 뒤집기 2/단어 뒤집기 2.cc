#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<char> v;
	stack<char> st;
	int i;
	bool flag = false;
	string s;
	getline(cin, s); // 공백 포함 입력
	for (i = 0; i < s.size(); i++) {
		if (s[i] == ' ') { // 공백이 나올시 현재까지 입력된 문자 뒤집기
			while (!st.empty()) {
				v.push_back(st.top());
				st.pop();
			}
			v.push_back(' ');
			continue; // 공백을 line21에서 직접 넣었기에 밑에 코드 넘기기
		}
		if (s[i] == '<') {
			if (!st.empty()) {
				while (!st.empty()) {
					v.push_back(st.top());
					st.pop();
				}
			}
			flag = true; // 뒤에 오는 문자들은 뒤집지 않고 입력
			v.push_back('<');
			continue;  // <을 line32에서 직접 넣었기에 밑에 코드 넘기기
		}
		if (s[i] == '>') {
			flag = false;
			v.push_back('>');
			continue;  // >을 line37에서 직접 넣었기에 밑에 코드 넘기기
		}
		if (flag) {
			if (st.empty())
				v.push_back(s[i]);
			/*else {
				while (!st.empty()) {
					v.push_back(st.top());
					st.pop();
				}
			}*/
		}
		else
			st.push(s[i]);
	}
	while (!st.empty()) {
		v.push_back(st.top());
		st.pop();
	}
	for (i = 0; i < v.size(); i++)
		cout << v[i];
}