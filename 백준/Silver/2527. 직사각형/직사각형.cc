#include <iostream>
#include <vector>
using namespace std;

bool set(vector<int>& v1, vector<int>& v2) {
	vector<int> tmp;
	if (v1[0] > v2[0]) {
		tmp = v1;
		v1 = v2;
		v2 = tmp;
		return false;
	}
	else if (v1[0] == v2[0]) {
		if (v1[1] > v2[1]) {
			tmp = v1;
			v1 = v2;
			v2 = tmp;
			return false;
		}
		else if (v1[1] == v2[1]) {
			if (v1[2] > v2[2]) {
				tmp = v1;
				v1 = v2;
				v2 = tmp;
				return false;
			}
			else if (v1[2] == v2[2]) {
				if (v1[3] > v2[3]) {
					tmp = v1;
					v1 = v2;
					v2 = tmp;
					return false;
				}
				else if (v1[3] == v2[3]) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 4;
	while (t--) {
		vector<int> v1(4), v2(4);
		for (int i = 0; i < 4; i++) cin >> v1[i];
		for (int i = 0; i < 4; i++) cin >> v2[i];

		if (set(v1, v2)) {
			cout << "a\n";
		}
		else {
			if (v1[2] < v2[0] || v1[3] < v2[1] || v1[1] > v2[3]) {
				cout << "d\n";
			}
			else if ((v1[2] == v2[0] && v1[3] == v2[1]) || (v1[2] == v2[0] && v1[1] == v2[3])) {
				cout << "c\n";
			}
			else if (v1[3] == v2[1] || v1[2] == v2[0] || v1[1] == v2[3]) {
				cout << "b\n";
			}
			else {
				cout << "a\n";
			}
		}
	}
}