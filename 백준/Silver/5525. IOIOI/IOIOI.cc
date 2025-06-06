#include <iostream>
#include <vector>
using namespace std;

vector<int> F;
int cnt = 0, n, m;

void failFunc(string P) {
	F[0] = 0;

	int i = 1, j = 0;
	while (i < n) {
		if (P[i] == P[j]) {
			F[i] = j + 1;
			i++, j++;
		}
		else if (j > 0) {
			j = F[j - 1];
		}
		else {
			F[i] = 0;
			i++;
		}
	}
}

void KMP(string T, string P) {
	failFunc(P);
	int i = 0, j = 0;
	while (i < m) {
		if (T[i] == P[j]) {
			if (j == n - 1) {
				cnt++;
				j = F[j];
				i++;
			}
			else {
				i++, j++;
			}
		}
		else if (j > 0) {
			j = F[j - 1];
		}
		else {
			i++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	string T, P = "I"; cin >> T;
	for (int i = 0; i < n; i++) P += "OI";

	n = P.size(); F.resize(n);

	KMP(T, P);

	cout << cnt;
}