#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[1000001] = {};
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = arr[0] > arr[n - 1] ? arr[0] : arr[n - 1];

	for (int i = 1; i < n - 1; i++) {
		int a = arr[i - 1] > arr[i + 1] ? arr[i + 1] : arr[i - 1];
		ans = ans > arr[i] + a ? ans : arr[i] + a;
	}

	cout << ans;
}