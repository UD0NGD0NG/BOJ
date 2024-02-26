#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, i, j, sum, max = 0;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> v[i][j];
	for (i = 0; i < n; i++) { // ㅡ
		for (j = 0; j < m - 3; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 3; i++) { // ㅣ
		for (j = 0; j < m; j++) {
			sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // ㅁ
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // ㅜ
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // ㅏ
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // ㅗ
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // ㅓ
		for (j = 0; j < m - 1; j++) {
			sum = v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // L(1)
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // L(2)
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 2][j];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // L(3)
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1] + v[i + 2][j];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // L(4)
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // L(5)
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // L(6)
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j + 2] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // L(7)
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // L(8)
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // Z(1)
		for (j = 0; j < m - 2; j++) {
			sum = v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 1; i++) { // Z(2)
		for (j = 0; j < m - 2; j++) {
			sum = v[i + 1][j] + v[i + 1][j + 1] + v[i][j + 1] + v[i][j + 2];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // Z(3)
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}
	for (i = 0; i < n - 2; i++) { // Z(4)
		for (j = 0; j < m - 1; j++) {
			sum = v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j];
			if (max < sum)
				max = sum;
		}
	}
	cout << max;
}