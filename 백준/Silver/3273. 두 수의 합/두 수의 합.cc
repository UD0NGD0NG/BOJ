#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end()); // 이분탐색을 위해 오름차순 정렬

	int x; cin >> x;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int aim = x - v[i]; // 찾아야 하는 목표값 저장
		int left = i + 1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (v[mid] == aim) { // 합이 x가 된다면
				cnt++; // 개수 증가
				break; // 수열 내에 중복된값이 없으므로 다음 케이스 탐색
			}
			else if (v[mid] < aim) { // 목표값보다 작다면
				left = mid + 1; // left를 오른쪽으로 옮겨 더 큰수의 범위에서 탐색
			}
			else { // 목표값보다 크다면
				right = mid - 1; // right를 왼쪽으로 옮겨 더 작은수의 범위에서 탐색
			}
		}
	}

	cout << cnt;
}