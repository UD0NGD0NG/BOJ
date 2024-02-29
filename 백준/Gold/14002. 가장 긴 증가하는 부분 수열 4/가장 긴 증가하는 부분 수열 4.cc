#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stack<int> st; // 큰값부터 저장 후 작은값부터 출력을 위한 LIFO컨테이너
	int arr[1000] = {}, dp[1000] = {};
	int n, i, j, max, ans = 0, idx = 1, len;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++) {
		max = 0;
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	for (i = 0; i < n; i++)
		if (ans < dp[i])
			ans = dp[i], idx = i;
	len = ans;
	for (; idx >= 0; idx--) {
		if (!len) // 모두 저장시(len == 0) 종료
			break;
		if (dp[idx] == len) { // 현재 길이와 같다면 저장
			st.push(arr[idx]);
			len--;
		}
	}
	cout << ans << '\n';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}