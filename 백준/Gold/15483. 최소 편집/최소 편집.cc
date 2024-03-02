#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[1001][1001] = {}; // 문제에서 주어진 최대조건만큼의 배열
	string a, b;
	cin >> a >> b;
	int al = a.size(), bl = b.size(), i, j;
	for (i = 0; i <= al; i++)
		arr[i][0] = i; // 배열의 첫번째 열 (line.15)
	for (i = 0; i <= bl; i++)
		arr[0][i] = i; // 배열의 첫번째 행 (line.16)
	for (i = 1; i <= al; i++) {
		for (j = 1; j <= bl; j++) {
			if (a[i - 1] - b[j - 1]) // 문자가 다르면 삽입 || 삭제 || 교환
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
			else // 같다면 그대로
				arr[i][j] = arr[i - 1][j - 1];
		}
	}
	cout << arr[i - 1][j - 1];
}