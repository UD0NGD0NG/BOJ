#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, N, M, i, j, sum, k;
	cin >> n >> m;
	N = n;
	vector<vector<int>> A(n, vector<int>(m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> A[i][j];
	cin >> n >> m;
	M = m;
	vector<vector<int>> B(n, vector<int>(m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> B[i][j];
	vector<vector<int>> v(N, vector<int>(M));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				sum += (A[i][k] * B[k][j]);
			}
			v[i][j] = sum;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}