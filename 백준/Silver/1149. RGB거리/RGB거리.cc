#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans[3], cost[3], tmp[3]; // 현재까지의 최소비용을 저장하는 ans, 비용을 입력받는 cost, 비교연산동안 ans의 값이 변하는걸 방지하기 위한 tmp 배열
	int n, i;
	cin >> n >> ans[0] >> ans[1] >> ans[2]; // 첫번째 집을 칠했을때의 최소비용은 해당 집을 칠한 비용
	for (i = 1; i < n; i++) { // 이후는 현재 집의 특정 색상비용 + 다른 색상의 앞집까지의 비용 중 작은값
		cin >> cost[0] >> cost[1] >> cost[2];
		tmp[0] = min(ans[1], ans[2]) + cost[0];
		tmp[1] = min(ans[0], ans[2]) + cost[1];
		tmp[2] = min(ans[1], ans[0]) + cost[2];
		ans[0] = tmp[0], ans[1] = tmp[1], ans[2] = tmp[2];
	}
	cout << min(ans[0], min(ans[1], ans[2]));
}