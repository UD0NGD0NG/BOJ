#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stack<pair<int, int>> candidate;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int height; cin >> height; // 현재 탑의 높이
		while (!candidate.empty() && height >= candidate.top().first) { // 바로 왼쪽 탑부터 현재 탑의 높이보다 높은 탑이 나올 떄 까지 탐색
			candidate.pop();
		}
		if (candidate.empty()) { // 왼쪽에 있는 탑중 현재 탑보다 높은 탑이 없는 경우
			cout << "0 ";
		}
		else {
			cout << candidate.top().second << ' '; // 있다면 해당 탑의 번호 출력
		}
		candidate.push(make_pair(height, i + 1)); // 현재 탑의 높이와 순서를 추가
	}
}