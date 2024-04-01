#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stack<int> candidate, st, ans; // 오등큰수의 후보 모음, 입력을 저장, 오등큰수 저장
	int cnt[1000001] = {}; // 나온 횟수 저장

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		st.push(a);
		cnt[a]++;
	}

	for (int i = 0; i < n; i++) {
		while (!candidate.empty() && cnt[st.top()] >= cnt[candidate.top()]) { // 오른쪽에 더 많이 나온 수가 있을때까지 탐색
			candidate.pop();
		}
		if (candidate.empty()) { // 없다면
			ans.push(-1); // 오등큰수는 -1
		}
		else { // 있다면
			ans.push(candidate.top()); // 오등큰수는 후보 중 top(가장 왼쪽)
		}
		candidate.push(st.top()); // 자신을 후보에 추가
		st.pop();
	}

	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
}