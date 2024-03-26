#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<int> liquid;
	for (int i = 0; i < n; i++) {
		int value; cin >> value; // 용액의 특성값
		liquid.push_back(value);
	}

	pair<int, int> ans;
	int min_val = 2000000001; // 두수의 합의 초기값은 불가능한 값중 가장 작은값(10억 + 10억 + 1)으로 설정

	for (int i = 0; i < n; i++) { // 시작 위치(첫번째 수의 위치)를 조정
		int left = i + 1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (abs(liquid[i] + liquid[mid]) < min_val) { // 현재 min_val보다 더 0에 가까운 값이 나왔다면(절대값이 더 작다면) 값 갱신
				ans = make_pair(liquid[i], liquid[mid]);
				min_val = abs(liquid[i] + liquid[mid]);
			}

			if (liquid[i] + liquid[mid] > 0) { // 양의값이 나왔다면 현재 값(mid)보다 더 작은수와 더했을 때를 비교해야 0과 가까워질 수 있으므로 right를 옮겨줌
				right = mid - 1;
			}
			else if (liquid[i] + liquid[mid] < 0) { // 음의값이 나왔다면 현재 값(mid)보다 더 큰수와 더했을 때를 비교해야 0과 가까워질 수 있으므로 left를 옮겨줌
				left = mid + 1;
			}
			else { // 0이라면 더 가까워질 수 없으므로 중단
				break;
			}
		}
	}

	cout << ans.first << ' ' << ans.second; // 시작 위치의 오른쪽에 대해서만 비교하기에 first가 더 작은값을 가짐
}