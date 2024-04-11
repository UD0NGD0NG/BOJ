#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<pair<int, int>> app(n);
	for (int i = 0; i < n; i++) cin >> app[i].first; // 사용 중인 메모리 바이트 수
	for (int i = 0; i < n; i++) cin >> app[i].second; // 비활성화 비용

	vector<vector<int>> byte(n, vector<int>(10001, -1)); // n번째 앱을 활성화 or 비활성화한 경우의 비용 당 확보한 바이트 수 저장
	byte[0][0] = 0, byte[0][app[0].second] = app[0].first;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (app[i].second <= j && byte[i - 1][j - app[i].second] != -1) { // 현재 앱을 비활성화한 비용과 비활성화 하지 않은 비용이 같을 때
				byte[i][j] = max(byte[i - 1][j], byte[i - 1][j - app[i].second] + app[i].first); // 둘 중 더 큰 메모리를 확보하는 정보 저장
			}
			else { // 새로 추가되는 경우
				byte[i][j] = byte[i - 1][j];
			}
		}
	}

	int ans = 10001; // 최악의 경우 사용되는 비활성화 비용 + 1
	for (int j = 0; j <= 10000; j++) {
		if (byte[n - 1][j] >= m) {
			ans = min(ans, j); // M바이트 이상 확보한 경우중 가장 적은 앱 비활성화 비용 탐색
		}
	}

	cout << ans;
}