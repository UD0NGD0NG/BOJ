#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<ll> liquid;
	for (int i = 0; i < n; i++) {
		ll value; cin >> value;
		liquid.push_back(value);
	}

	sort(liquid.begin(), liquid.end()); // 이분탐색을 위한 정렬

	tuple<ll, ll, ll> ans;
	ll min_val = 3000000001; // 최악의 경우 + 1

	for (int i = 0; i < n; i++) { // 모든 용액을 대상으로 첫번째 용액 선택
		for (int j = i + 1; j < n; j++) { // 아직 탐색하지 않은 구역에서 두번째 용액 선택
			int left = j + 1, right = n - 1;  // 남은 구역에서 
			while (left <= right) { // 이분탐색을 하며
				int mid = (left + right) / 2;

				if (abs(liquid[i] + liquid[j] + liquid[mid]) < min_val) { // 현재보다 더 0에 가까운 용액을 만들 수 있다면
					ans = make_tuple(liquid[i], liquid[j], liquid[mid]); // 정답 갱신
					min_val = abs(liquid[i] + liquid[j] + liquid[mid]);
				}

				if (liquid[i] + liquid[j] + liquid[mid] > 0) {
					right = mid - 1;
				}
				else if (liquid[i] + liquid[j] + liquid[mid] < 0) {
					left = mid + 1;
				}
				else {
					break;
				}
			}
		}
	}

	cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
}