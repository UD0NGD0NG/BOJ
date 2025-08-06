#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pos = pair<int, int>;
using node = pair<pos, int>;

vector<vector<int>> house;
queue<pair<pos, int>> pipe;
int N, ans;

bool isValid(pos p) {
	return ((p.first < N && p.second < N) && !house[p.first][p.second]);
}

void solve(node n) {
	if (n.first == make_pair(N - 1, N - 1)) {
		ans++;
		return;
	}

	if (n.second == 1) {
		if (isValid({ n.first.first, n.first.second + 1 })) {
			pipe.push({ {n.first.first, n.first.second + 1}, 1 });
		}
		
		if (isValid({ n.first.first, n.first.second + 1 }) && isValid({ n.first.first + 1, n.first.second }) && isValid({ n.first.first + 1, n.first.second + 1 })) {
			pipe.push({ {n.first.first + 1, n.first.second + 1}, 3 });
		}
	}
	else if (n.second == 2) {
		if (isValid({ n.first.first + 1, n.first.second })) {
			pipe.push({ {n.first.first + 1, n.first.second}, 2 });
		}

		if (isValid({ n.first.first, n.first.second + 1 }) && isValid({ n.first.first + 1, n.first.second }) && isValid({ n.first.first + 1, n.first.second + 1 })) {
			pipe.push({ {n.first.first + 1, n.first.second + 1}, 3 });
		}
	}
	else {
		if (isValid({ n.first.first, n.first.second + 1 })) {
			pipe.push({ {n.first.first, n.first.second + 1}, 1 });
		}

		if (isValid({ n.first.first + 1, n.first.second })) {
			pipe.push({ {n.first.first + 1, n.first.second}, 2 });
		}

		if (isValid({ n.first.first, n.first.second + 1 }) && isValid({ n.first.first + 1, n.first.second }) && isValid({ n.first.first + 1, n.first.second + 1 })) {
			pipe.push({ {n.first.first + 1, n.first.second + 1}, 3 });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	house.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}

	pipe.push({ {0, 1}, 1 });
	while (!pipe.empty()) {
		solve(pipe.front());
		pipe.pop();
	}

	cout << ans;
}