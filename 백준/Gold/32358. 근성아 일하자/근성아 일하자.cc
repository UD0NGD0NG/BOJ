#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int pos = 0, n; cin >> n;
	long long dist = 0;

	priority_queue<int> pqL, pqR;

	while (n--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int x; cin >> x;
			x < pos ? pqL.push(x) : pqR.push(-x);
		}
		else {
			while (!pqL.empty() || !pqR.empty()) {
				if (pqL.empty() && !pqR.empty()) {
					dist += -pqR.top() - pos;
					pos = -pqR.top();
					pqR.pop();
				}
				else if (!pqL.empty() && pqR.empty()) {
					dist += pos - pqL.top();
					pos = pqL.top();
					pqL.pop();
				}
				else {
					if (pos - pqL.top() <= -pqR.top() - pos) {
						dist += pos - pqL.top();
						pos = pqL.top();
						pqL.pop();
					}
					else {
						dist += -pqR.top() - pos;
						pos = -pqR.top();
						pqR.pop();
					}
				}
			}
		}
	}

	cout << dist;
}