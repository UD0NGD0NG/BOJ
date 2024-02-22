#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[100000];
	vector<char> v;
	stack<int> st;
	int n, i, idx = 0, flag = 1;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];

		if (!flag && arr[i - 1] < arr[i]) { // push연산이 불가능한 경우에서 수열의 이전 칸이 현재 칸보다 큰 경우 해당 수열을 만들 수 없음
			cout << "NO";
			return 0;
		}

		if (arr[i] == n) flag = 0; // 최댓값이 나온경우 더이상 push연산을 할 수 없음
	}

	for (i = 1; i <= n; i++) {
		st.push(i); // 1부터 n까지 차례대로 stack에 삽입
		v.push_back('+');
		while (!st.empty() && arr[idx] == st.top()) { // 현재 idx와 stack에 마지막에 들어간 값이 같다면
			v.push_back('-'), st.pop(); // pop연산을 해주고
			idx++; // idx를 다음칸으로 바꿔줌
		}
	}

	if (st.size()) { // 만약 line.25의 반복문이 종료되었을 때 stack에 값이 남아있는 경우 해당 수열을 만들 수 없음(pop연산만 가능한 상태이기 때문)
		cout << "NO";
	}
	else {
		for (char x : v) {
			cout << x << '\n';
		}
	}
}