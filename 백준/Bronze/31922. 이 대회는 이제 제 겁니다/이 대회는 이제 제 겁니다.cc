#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, p, c; cin >> a >> p >> c;
	a + c > p ? cout << a + c : cout << p;
}