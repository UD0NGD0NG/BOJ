#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, w, v, i, j, ans = 0;
	cin >> n >> k; // 물품의 수, 버틸 수 있는 무게
	vector<vector<int>> bag(n, vector<int>(k + 1, -1));
	vector<pair<int, int>> obj(n);
	for (i = 0; i < n; i++) {
		cin >> w >> v; // 물건의 무게, 물건의 가치
		obj[i] = make_pair(w, v);
	}
	bag[0][obj[0].first] = obj[0].second;
	for (i = 0; i < n; i++)
		bag[i][0] = 0;
	for (i = 1; i < n; i++) {
		for (j = 0; j <= k; j++) {
			if (obj[i].first <= j && bag[i - 1][j - obj[i].first] != -1) // 현재 물건을 안넣었을 때의 무게에 대한 정보가 저장되어 있는 경우
				bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - obj[i].first] + obj[i].second); // 현재 물건을 넣는 것의 가치가 더 큰지 이전까지의 물건을 넣어둔 것의 가치가 더 큰지 비교
			else
				bag[i][j] = bag[i - 1][j];
		}
	}
	for (i = 0; i <= k; i++)
		if (ans < bag[n - 1][i]) // 모든 물건을 넣을지 말지 결정한 이후의 상황에서
			ans = bag[n - 1][i]; // 최대 가치 판정
	cout << ans;
}