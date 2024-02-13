#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	multiset<int> q; // set과 같이 오름차순 정렬을 해주면서도 중복된 값을 저장 가능
	int t, k, n;
	char c;
	cin >> t;
	while (t--) {
		cin >> k;
		while (k--) {
			cin >> c >> n;
			if (c == 'I')
				q.insert(n);
			else if (!q.empty()) {
				if (n == 1) {
					q.erase(--q.end()); // multiset의 마지막 값(최댓값)을 지워줌, erase의 매개변수로 반복자는
				}
				else {
					q.erase(q.begin()); // multiset의 처음 값(최솟값)을 지워줌
				}
			}
		}
		if (q.empty())
			cout << "EMPTY\n";
		else
			cout << *q.rbegin() << ' ' << *q.begin() << '\n'; // rbegin() == --end()
		q.clear();
	}
}