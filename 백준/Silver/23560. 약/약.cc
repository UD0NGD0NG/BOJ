#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[16]{}; arr[1] = 2;
	for (int i = 2; i <= 15; i++) {
		for (int j = 1; j < i; j++) {
			arr[i] += arr[j] * 2;
		}
		arr[i] += 2;
	}

	int n; cin >> n;
	cout << arr[n];
}