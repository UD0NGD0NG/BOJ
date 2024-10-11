#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q; cin >> q;

	int idx = 0; // 0: b-f, 1: f|b, 2: f-b, 3: b|f

	deque<int> dq;
	int cntb = 0, cntw = 0;
	while (q--) {
		string cmd; cin >> cmd;

		if (cmd == "push") {
			string s; cin >> s;

			if (s == "b") {
				if (idx == 0 || idx == 2) {
					dq.push_back(0);
					cntb++;
				}
				else if (idx == 3) {
					if (!dq.empty()) {
						dq.push_back(0);
						cntb++;
					}
				}
			}
			else {
				dq.push_back(1);
				cntw++;
			}
		}
		else if (cmd == "pop") {
			if (!dq.empty()) {
				if (idx == 0 || idx == 1 || idx == 2) {
					if (dq.front()) cntw--;
					else cntb--;

					dq.pop_front();
				}
				else if (idx == 3) {
					if (dq.front()) {
						cntw--;

						dq.pop_front();

						while (!dq.empty() && !dq.front()) {
							dq.pop_front();
							cntb--;
						}
					}
					else {
						cntb--;

						dq.pop_front();
					}
				}
			}
		}
		else if (cmd == "rotate") {
			string s; cin >> s;

			if (s == "l") idx = (idx + 1) % 4;
			else idx = (idx + 3) % 4;

			if (idx == 1) {
				while (!dq.empty() && !dq.back()) {
					dq.pop_back();
					cntb--;
				}
			}
			else if (idx == 3) {
				while (!dq.empty() && !dq.front()) {
					dq.pop_front();
					cntb--;
				}
			}
		}
		else if (cmd == "count") {
			string s; cin >> s;
			if (s == "b") cout << cntb << '\n';
			else cout << cntw << '\n';
		}
	}
}