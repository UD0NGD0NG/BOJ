#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unsigned long long n; cin >> n;
	(n % 4 == 1 || n % 4 == 3) ? cout << "SK" : cout << "CY";
}