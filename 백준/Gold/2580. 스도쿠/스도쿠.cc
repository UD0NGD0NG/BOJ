#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;

vector<vector<char>> sudoku(9, vector<char>(9));
vector<set<char>> row(9);
vector<set<char>> col(9);
vector<set<char>> box(9);
deque<pair<int, int>> zero;

void backtracking() {
	if (!zero.empty()) {
		int x = zero.front().first, y = zero.front().second;
		for (char i = '1'; i <= '9'; i++) {
			if (!(row[x].count(i)) && !(col[y].count(i)) && !(box[(x / 3) * 3 + (y / 3)].count(i))) {
				sudoku[x][y] = i;

				row[x].insert(i);
				col[y].insert(i);
				box[(x / 3) * 3 + (y / 3)].insert(i);
				zero.pop_front();

				backtracking();

				if (!zero.empty()) {
					row[x].erase(i);
					col[y].erase(i);
					box[(x / 3) * 3 + (y / 3)].erase(i);
					zero.push_front(make_pair(x, y));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];

			if (sudoku[i][j] - '0') {
				row[i].insert(sudoku[i][j]);
				col[j].insert(sudoku[i][j]);
				box[(i / 3) * 3 + (j / 3)].insert(sudoku[i][j]);
			}
			else {
				zero.push_back(make_pair(i, j));
			}
		}
	}

	backtracking();

	for (auto x : sudoku) {
		for (auto y : x) {
			cout << y << ' ';
		}
		cout << '\n';
	}
}
