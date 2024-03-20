#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void Prime(vector<int>& v) { // 에라토스테네스의 체
	v[0] = 0, v[1] = 0;

	for (int i = 2; i < v.size(); i++) {
		if (v[i]) {
			for (int j = 2; i * j < v.size(); j++) {
				v[i * j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	Prime(v);

	vector<ll> prime(1, 0);
	ll sum = 0;
	for (int i = 2; i <= n; i++) {
		if (v[i]) { // 소수를 가지고
			sum += i;
			prime.push_back(sum); // 누적합 배열 생성
		}
	}

	int cnt = 0;
	for (int i = 1; i < prime.size(); i++) {
		ll left = i, right = prime.size() - 1;
		while (left <= right) { // parametric search를 사용하여
			ll mid = (left + right) / 2;
			if (prime[mid] - prime[i - 1] == n) { // 구간합이 n이면 
				cnt++; // 개수 증가
				break;
			}
			else if (prime[mid] - prime[i - 1] > n) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	cout << cnt;
}