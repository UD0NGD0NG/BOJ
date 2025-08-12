#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
using Line = vector<int>;
using Matrix = vector<vector<int>>;

int N;
Matrix Zero, One;
unordered_map<ll, Matrix> dp;

Matrix Mul(Matrix A, Matrix B) {
	Matrix AB(N, Line(N, 0));
	int partN = N / 2;
	for (int i = 0; i < partN; i++) {
		for (int j = 0; j < partN; j++) {
			for (int k = 0; k < partN; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}
	for (int i = 0; i < partN; i++) {
		for (int j = partN; j < N; j++) {
			for (int k = 0; k < partN; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}

	for (int i = 0; i < partN; i++) {
		for (int j = 0; j < partN; j++) {
			for (int k = partN; k < N; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}
	for (int i = 0; i < partN; i++) {
		for (int j = partN; j < N; j++) {
			for (int k = partN; k < N; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}

	for (int i = partN; i < N; i++) {
		for (int j = 0; j < partN; j++) {
			for (int k = 0; k < partN; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}
	for (int i = partN; i < N; i++) {
		for (int j = partN; j < N; j++) {
			for (int k = 0; k < partN; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}

	for (int i = partN; i < N; i++) {
		for (int j = 0; j < partN; j++) {
			for (int k = partN; k < N; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}
	for (int i = partN; i < N; i++) {
		for (int j = partN; j < N; j++) {
			for (int k = partN; k < N; k++) {
				AB[i][k] += (A[i][j] * B[j][k]) % 1000;
				AB[i][k] %= 1000;
			}
		}
	}

	return AB;
}

void Solve(ll n) {
	if (!dp[n].empty()) return;

	if (n % 2) {
		ll l = n / 2, r = l + 1;
		if (dp[l].empty()) {
			Solve(l);
		}
		if (dp[r].empty()) {
			Solve(r);
		}
		dp[n] = Mul(dp[l], dp[r]);
	}
	else {
		if (dp[n / 2].empty()) {
			Solve(n / 2);
		}
		dp[n] = Mul(dp[n / 2], dp[n / 2]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll b; cin >> N >> b;
	Matrix A(N, Line(N)); for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { cin >> A[i][j]; A[i][j] %= 1000; }

	Zero.resize(N, Line(N, 0));
	One.resize(N, Line(N, 1));
	if (A == Zero || A == One) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << A[i][j] << ' ';
			}
			cout << '\n';
		}
		return 0;
	}

	dp[1] = A;
	Solve(b);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[b][i][j] << ' ';
		}
		cout << '\n';
	}
}