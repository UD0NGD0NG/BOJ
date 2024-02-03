#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<long, int> mp;
	queue<long> q;
	long a, b;
	cin >> a >> b;
	mp[a] = 1; // 연산횟수를 1로 잡아 마지막에 +1을 하지 않아도 가능
	q.push(a);
	while (!q.empty()) {
		long x = q.front();
		q.pop();
		if (x * 2 <= b && !mp[x * 2]) { // 값을 축소하는 연산은 불가능하기에 목적(B) 값을 제한조건으로 설정 && 방문여부 체크
			mp[x * 2] = mp[x] + 1;
			q.push(x * 2);
		}
		if (x * 10 + 1 <= b && !mp[x * 10 + 1]) {
			mp[x * 10 + 1] = mp[x] + 1;
			q.push(x * 10 + 1);
		}
	}
	if (mp.find(b) != mp.end()) // 만들 수 있는 경우
		cout << mp[b];
	else // 만들 수 없는 경우
		cout << -1;
}