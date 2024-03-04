#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int memo[50001] = {}; // 제곱수의 최소 개수 저장
	int n, i, j;

	for (i = 1; i * i < 50001; i++) memo[i * i] = 1; // 제곱수는 1로 미리 초기화

	cin >> n;
	for (i = 1; i <= n; i++) {
		if (!memo[i]) { // 값이 아직 정해지지 않았다면(제곱수가 아니라면)
			memo[i] = 4; // 라그랑주 네 제곱수 정리에 따라 최악의 경우인 4로 임의 설정

			for (j = 1; j * j < i; j++) { 
				memo[i] = min(memo[i], memo[i - j * j] + 1); // (현재값 - 제곱수)는 이미 값이 최소 개수로 정해져있으므로 (현재값 - 제곱수)에 제곱수를 더해준(해당 값에 1개를 추가한)값과 현재 값중 작은값을 저장
			}
		}
	}
    
	cout << memo[n];
}