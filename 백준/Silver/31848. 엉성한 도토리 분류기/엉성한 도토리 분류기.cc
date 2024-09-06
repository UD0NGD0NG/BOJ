#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<int> dp(n + 1); // 크기가 index인 경우 빠지게 되는 가장 앞쪽 구멍 번호를 저장
	int pre = 0;

	stack<int> st;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		if (st.empty() || st.top() <= s + i) { // 현재 구멍이 이전까지의 구멍들보다 큰 사이즈의 도토리를 떨어트릴 수 있다면 갱신
			st.push(s + i);

			for (int j = pre + 1; j <= min(st.top(), n); j++) {
				dp[j] = i + 1;
			}

			pre = st.top();
		}
	}

	int q; cin >> q;
	while (q--) {
		int s; cin >> s;
		cout << dp[s] << ' ';
	}
}