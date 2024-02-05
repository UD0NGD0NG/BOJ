#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[1001][1001] = {}, i, j; // 문제의 최대 조건치만큼 배열선언
	string a, b;
	cin >> a >> b;
	for (i = 1; i <= a.size(); i++) {
		for (j = 1; j <= b.size(); j++) {
			if (a[i - 1] - b[j - 1]) // a의 i번째 글자와 b의 j번째 글자가 다르면
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]); // 좌측값과 상단값 비교
			else // 같으면
				arr[i][j] = arr[i - 1][j - 1] + 1; // 해당 글자가 아직 안나온 시점 + 1
		}
	}
	cout << arr[i - 1][j - 1];
}