#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, w = 0, b = 0, l;
    int i, j, x, y, flag;
    cin >> n; l = n; // l은 탐색할 변의 길이를 저장함

    vector<vector<bool>> visit(n, vector<bool>(n, false));
    vector<vector<int>> v(n, vector<int>(n));
    for (i = 0; i < n; i++) { // 색종이 구성
        for (j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    while (l) { // 변의 길이가 0이 아닐때까지
        for (i = 0; i <= n - l; i += l) {
            for (j = 0; j <= n - l; j += l) {
                if (visit[i][j]) continue; // 이미 탐색한 영역이면 넘기기 (변의 길이는 점점 작아지기에 더 큰 변일때 좌상단 영역을 방문했다면 더 작은 변으로 이루어진 영역중 방문하지 않은 영역이 있을 수 없음)

                flag = 1;
                for (x = 0; x < l; x++) {
                    for (y = 0; y < l; y++) {
                        if (v[i][j] != v[i + x][j + y]) {
                            flag = 0; // 탐색영역에 다른 숫자가 있는 경우 해당 영역은 하나의 색종이가 될 수 없음
                            break;
                        }
                    }
                    if (!flag) break;
                }

                if (flag) { // 해당영역이 모두 같은 숫자로 이루어져있어 하나의 색종이가 될 수 있다면
                    if (v[i][j]) // 숫자에 따라 색종이의 수를 증가하고
                        b++;
                    else
                        w++;

                    for (x = 0; x < l; x++) { // 해당영역을 방문처리
                        for (y = 0; y < l; y++) {
                            visit[i + x][j + y] = true;
                        }
                    }
                }
            }
        }
        l /= 2; // 탐색영역 줄이기
    }
    cout << w << '\n' << b;
}