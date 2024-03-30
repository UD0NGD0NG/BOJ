#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<vector<int>> ladder(101);
	while (n--) {
		int x, y; cin >> x >> y;
		ladder[x].push_back(y);
	}

	vector<vector<int>> snake(101);
	while (m--) {
		int u, v; cin >> u >> v;
		snake[u].push_back(v);
	}

	vector<int> cnt(101, -1);
	cnt[1] = 0;

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int y : ladder[x]) { // 사다리를 타고 올라가는 경우
			if (cnt[y] == -1 || cnt[y] > cnt[x]) { // 아직 안간곳이거나 빠르게 도달하게 된다면
				cnt[y] = cnt[x]; // 값 갱신 후
				q.push(y); // 해당 칸을 기준으로 재탐색
			}
		}

		for (int i = 1; i <= 6; i++) { // 주사위를 굴려 도달하는 경우
			if (x + i <= 100) { // 100보다 커지지 않는 범위에서
				if (snake[x + i].empty()) { // 도착칸에 뱀이 없는 경우
					if ((cnt[x + i] == -1 || cnt[x + i] > cnt[x])) { // 아직 안간곳이거나 더 빠르게 도달하는 경우에 한해
						cnt[x + i] = cnt[x] + 1; // 값 갱신 후
						q.push(x + i); // 해당 칸을 기준으로 재탐색
					}
				}
				else { // 도착칸에 뱀이 있다면
					if (cnt[snake[x + i][0]] == -1 || cnt[snake[x + i][0]] > cnt[x]) { // 아직 안간곳이거나 더 빠르게 도달하는 경우
						cnt[snake[x + i][0]] = cnt[x] + 1; // 값 갱신 후
						q.push(snake[x + i][0]); // 해당 칸을 기준으로 재탐색
					}
				}
			}
		}
	}

	cout << cnt[100];
}