#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<tuple<int, int, int>> v; // 집 정보 저장
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back(make_tuple(a, b, c));
	}

	int ans[3], cost[3], tmp[3], res[3];

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans[0] = get<0>(v[i]), ans[1] = get<1>(v[i]), ans[2] = get<2>(v[i]);
		}
		else {
			cost[0] = get<0>(v[i]), cost[1] = get<1>(v[i]), cost[2] = get<2>(v[i]);

			if (i == 1) {
				tmp[0] = 2000;
				tmp[1] = ans[0] + cost[1];
				tmp[2] = ans[0] + cost[2];
			}
			else if (i == n - 1) {
				tmp[0] = 1000 * n;
				tmp[1] = min(ans[0], ans[2]) + cost[1];
				tmp[2] = min(ans[1], ans[0]) + cost[2];
			}
			else {
				tmp[0] = min(ans[1], ans[2]) + cost[0];
				tmp[1] = min(ans[0], ans[2]) + cost[1];
				tmp[2] = min(ans[1], ans[0]) + cost[2];
			}

			ans[0] = tmp[0], ans[1] = tmp[1], ans[2] = tmp[2];
		}
	}
	res[0] = min(ans[1], ans[2]); // 1번집이 빨간색으로 칠해진 경우

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans[0] = get<0>(v[i]), ans[1] = get<1>(v[i]), ans[2] = get<2>(v[i]);
		}
		else {
			cost[0] = get<0>(v[i]), cost[1] = get<1>(v[i]), cost[2] = get<2>(v[i]);

			if (i == 1) {
				tmp[0] = ans[1] + cost[0];
				tmp[1] = 2000;
				tmp[2] = ans[1] + cost[2];
			}
			else if (i == n - 1) {
				tmp[0] = min(ans[1], ans[2]) + cost[0];
				tmp[1] = 1000 * n;
				tmp[2] = min(ans[1], ans[0]) + cost[2];
			}
			else {
				tmp[0] = min(ans[1], ans[2]) + cost[0];
				tmp[1] = min(ans[0], ans[2]) + cost[1];
				tmp[2] = min(ans[1], ans[0]) + cost[2];
			}

			ans[0] = tmp[0], ans[1] = tmp[1], ans[2] = tmp[2];
		}
	}
	res[1] = min(ans[2], ans[0]); // 1번집이 초록색으로 칠해진 경우

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans[0] = get<0>(v[i]), ans[1] = get<1>(v[i]), ans[2] = get<2>(v[i]);
		}
		else {
			cost[0] = get<0>(v[i]), cost[1] = get<1>(v[i]), cost[2] = get<2>(v[i]);

			if (i == 1) {
				tmp[0] = ans[2] + cost[0];
				tmp[1] = ans[2] + cost[1];
				tmp[2] = 2000;
			}
			else if (i == n - 1) {
				tmp[0] = min(ans[1], ans[2]) + cost[0];
				tmp[1] = min(ans[0], ans[2]) + cost[1];
				tmp[2] = 1000 * n;
			}
			else {
				tmp[0] = min(ans[1], ans[2]) + cost[0];
				tmp[1] = min(ans[0], ans[2]) + cost[1];
				tmp[2] = min(ans[1], ans[0]) + cost[2];
			}

			ans[0] = tmp[0], ans[1] = tmp[1], ans[2] = tmp[2];
		}
	}
	res[2] = min(ans[0], ans[1]); // 1번집이 파란색으로 칠해진 경우

	cout << min(res[0], min(res[1], res[2]));
}