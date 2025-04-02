#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 0;

bool isValid(pair<int, int> c, int pos) {
	switch (pos) {
	case 0:
		return 2 < c.first;
	case 1:
		return 2 < c.first && c.second < m - 3;
	case 2:
		return c.second < m - 3;
	case 3:
		return c.first < n - 3 && c.second < m - 3;
	case 4:
		return c.first < n - 3;
	case 5:
		return c.first < n - 3 && 2 < c.second;
	case 6:
		return 2 < c.second;
	case 7:
		return 2 < c.first && 2 < c.second;
	}
}

bool isMBTI(pair<int, int> c, int pos, vector<vector<char>>& board) {
	int i = c.first, j = c.second;
	switch (pos) {
	case 0:
		return (board[i - 1][j] == 'N' || board[i - 1][j] == 'S') && (board[i - 2][j] == 'F' || board[i - 2][j] == 'T') && (board[i - 3][j] == 'P' || board[i - 3][j] == 'J');
	case 1:
		return (board[i - 1][j + 1] == 'N' || board[i - 1][j + 1] == 'S') && (board[i - 2][j + 2] == 'F' || board[i - 2][j + 2] == 'T') && (board[i - 3][j + 3] == 'P' || board[i - 3][j + 3] == 'J');
	case 2:
		return (board[i][j + 1] == 'N' || board[i][j + 1] == 'S') && (board[i][j + 2] == 'F' || board[i][j + 2] == 'T') && (board[i][j + 3] == 'P' || board[i][j + 3] == 'J');
	case 3:
		return (board[i + 1][j + 1] == 'N' || board[i + 1][j + 1] == 'S') && (board[i + 2][j + 2] == 'F' || board[i + 2][j + 2] == 'T') && (board[i + 3][j + 3] == 'P' || board[i + 3][j + 3] == 'J');
	case 4:
		return (board[i + 1][j] == 'N' || board[i + 1][j] == 'S') && (board[i + 2][j] == 'F' || board[i + 2][j] == 'T') && (board[i + 3][j] == 'P' || board[i + 3][j] == 'J');
	case 5:
		return (board[i + 1][j - 1] == 'N' || board[i + 1][j - 1] == 'S') && (board[i + 2][j - 2] == 'F' || board[i + 2][j - 2] == 'T') && (board[i + 3][j - 3] == 'P' || board[i + 3][j - 3] == 'J');
	case 6:
		return (board[i][j - 1] == 'N' || board[i][j - 1] == 'S') && (board[i][j - 2] == 'F' || board[i][j - 2] == 'T') && (board[i][j - 3] == 'P' || board[i][j - 3] == 'J');
	case 7:
		return (board[i - 1][j - 1] == 'N' || board[i - 1][j - 1] == 'S') && (board[i - 2][j - 2] == 'F' || board[i - 2][j - 2] == 'T') && (board[i - 3][j - 3] == 'P' || board[i - 3][j - 3] == 'J');
	}
}

void solve(pair<int, int> c, vector<vector<char>>& board) {
	for (int pos = 0; pos < 8; pos++) {
		if (isValid(c, pos) && isMBTI(c, pos, board)) {
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<pair<int, int>> candidate;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == 'E' || c == 'I') {
				candidate.push_back({ i, j });
			}
			board[i][j] = c;
		}
	}

	for (auto c : candidate) {
		solve(c, board);
	}

	cout << ans;
}