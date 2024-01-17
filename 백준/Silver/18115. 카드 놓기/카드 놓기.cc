#include <iostream>
#include <list>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stack<int> st; // 기술을 반대로 사용하기 위해 LIFO 자료구조 사용
	list<int> l; // 앞에서 2번째 위치에 값을 삽입해줘야 하므로 list사용
	list<int>::iterator it;
	int n, x, now = 1;
	cin >> n;
	while (n--) {
		cin >> x;
		st.push(x);
	}
	while (!st.empty()) {
		x = st.top();
		if (x == 1)
			l.push_front(now);
		if (x == 2) {
			it = l.begin();
			it++; // 2번째 위치로 변경
			l.insert(it, now);
		}
		if (x == 3)
			l.push_back(now);
		now++;
		st.pop();
	}
	for (it = l.begin(); it != l.end(); it++)
		cout << *it << ' ';
}