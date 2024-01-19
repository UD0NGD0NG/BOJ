#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<char> v; // 결과를 저장
	stack<char> st; // 부분 문자열을 뒤집기 위해 임시저장
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
		if (s[i] == '<') { // <이 나올시 현재까지 입력된 문자 뒤집기
			if (!st.empty()) {
				while (!st.empty()) {
					v.push_back(st.top());
					st.pop();
				}
			}
			flag = true; // <>안에 있음을 나타냄
			v.push_back('<');
			continue;  // <을 line32에서 직접 넣었기에 밑에 코드 넘기기
		}
		if (s[i] == '>') {
			flag = false;  // <>을 벗어남을 나타냄
			v.push_back('>');
			continue;  // >을 line37에서 직접 넣었기에 밑에 코드 넘기기
		}
		if (flag)
			v.push_back(s[i]); // 뒤집지 않고 저장
		else
			st.push(s[i]); // 뒤집기 위해 stack에 임시 저장
	}
	while (!st.empty()) { // 마지막 문자가 >가 아닌경우를 위함
		v.push_back(st.top());
		st.pop();
	}
	for (i = 0; i < v.size(); i++)
		cout << v[i];
}
