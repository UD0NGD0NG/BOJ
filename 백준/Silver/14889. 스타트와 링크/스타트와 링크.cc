#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, ans = 1000; // 최악으로 조가 짜인 경우의 점수 차(0 * 10 vs 100 * 10)
int team[20][20];
set<int> a; // 빈상태로 시작
set<int> b; // 0 ~ n - 1로 채워진 상태로 시작

void backtracking(int idx) {
	if (a.size() == n / 2) { // 반이 넘어가면
		int sumA = 0, sumB = 0;

		// 각 팀의 점수를 구하고
		set<int>::iterator it1, it2;
		for (it1 = a.begin(); it1 != a.end(); it1++) {
			for (it2 = a.begin(); it2 != a.end(); it2++) {
				sumA += team[*it1][*it2];
			}
		}

		for (it1 = b.begin(); it1 != b.end(); it1++) {
			for (it2 = b.begin(); it2 != b.end(); it2++) {
				sumB += team[*it1][*it2];
			}
		}

		ans = min(ans, abs(sumA - sumB)); // 점수차를 최솟값으로 갱신
		return;
	}

	for (int i = idx; i < n; i++) {
		a.insert(i); // i를 a팀에 넣을 시
		b.erase(i); // b팀에는 삭제

		backtracking(i + 1); // i가 중복으로 들어갈 수 없도록 유지

		a.erase(i); // 탐색이 끝나면 i를 다시 b팀으로 복귀
		b.insert(i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		b.insert(i);
		for (int j = 0; j < n; j++) {
			cin >> team[i][j];
		}
	}

	backtracking(0);

	cout << ans;
}