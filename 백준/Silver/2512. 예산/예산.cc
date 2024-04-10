#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n; cin >> n;
	int limit = 0;

	int arr[10000] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		limit = max(limit, arr[i]); // 예산의 최댓값 정하기
	}

	int m; cin >> m;
	int left = 1, right = m;

	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) sum += arr[i]; // 현재 줄 수 있는 예산범위 내에 있다면 더하기
			else sum += mid;
		}

		if (sum > m) { // 현재 예산의 최댓값보다 작은 예산들의 합이 m보다 크다면 limit값 줄이기
			right = mid - 1;
		}
		else { // 그렇지 않다면 limit값 늘리기
			left = mid + 1;
			ans = max(ans, mid);
		}
	}

	cout << min(ans, limit); // 2번 경우 고려
}