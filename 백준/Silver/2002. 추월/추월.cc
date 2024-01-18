#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<string, int> mp; // 들어간 순서를 저장
	vector<string> v; // 나온 순서를 저장
	int n, i, j, cnt = 0;
	string c; // 차량번호
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> c;
		mp[c] = i;
	}
	for (i = 0; i < n; i++) {
		cin >> c;
		v.push_back(c);
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (mp[v[i]] > mp[v[j]]) { // 늦게 나온 차량 중 먼저 들어간 차량이 있다면
				cnt++; // 추월한 차량 수 +1
				break;
			}
		}
	}
	cout << cnt;
}
