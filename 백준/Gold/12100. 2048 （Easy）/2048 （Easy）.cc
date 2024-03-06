#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, score = 0;
vector<vector<int>> v(20, vector<int>(20, -1)); // 2048판의 형태 저장
vector<int> order; // 이동 정보 저장


void Move(int o) {
    if (o == 1) { // 상
        for (int j = 0; j < n; j++) {
            vector<bool> visit(n, false); // 합쳐짐 여부 확인
            for (int i = 1; i < n; i++) {
                if (i == 0 || v[i][j] == 0) continue;

                if (v[i - 1][j] == 0) {
                    v[i - 1][j] = v[i][j];
                    v[i][j] = 0;
                    i -= 2;
                }
                else if (v[i - 1][j] == v[i][j] && !visit[i - 1]) {
                    v[i - 1][j] *= 2;
                    visit[i - 1] = true;
                    v[i][j] = 0;
                }
            }
        }
    }
    else if (o == 2) { // 하
        for (int j = 0; j < n; j++) {
            vector<bool> visit(n, false);
            for (int i = n - 2; i >= 0; i--) {
                if (i == n - 1 || v[i][j] == 0) continue;

                if (v[i + 1][j] == 0) {
                    v[i + 1][j] = v[i][j];
                    v[i][j] = 0;
                    i += 2;
                }
                else if (v[i + 1][j] == v[i][j] && !visit[i + 1]) {
                    v[i + 1][j] *= 2;
                    visit[i + 1] = true;
                    v[i][j] = 0;
                }
            }
        }
    }
    else if (o == 3) { // 좌
        for (int i = 0; i < n; i++) {
            vector<bool> visit(n, false);
            for (int j = 1; j < n; j++) {
                if (j == 0 || v[i][j] == 0) continue;

                if (v[i][j - 1] == 0) {
                    v[i][j - 1] = v[i][j];
                    v[i][j] = 0;
                    j -= 2;
                }
                else if (v[i][j - 1] == v[i][j] && !visit[j - 1]) {
                    v[i][j - 1] *= 2;
                    visit[j - 1] = true;
                    v[i][j] = 0;
                }
            }
        }
    }
    else { // 우(o == 4)
        for (int i = 0; i < n; i++) {
            vector<bool> visit(n, false);
            for (int j = n - 2; j >= 0; j--) {
                if (j == n - 1 || v[i][j] == 0) continue;

                if (v[i][j + 1] == 0) {
                    v[i][j + 1] = v[i][j];
                    v[i][j] = 0;
                    j += 2;
                }
                else if (v[i][j + 1] == v[i][j] && !visit[j + 1]) {
                    v[i][j + 1] *= 2;
                    visit[j + 1] = true;
                    v[i][j] = 0;
                }
            }
        }
    }
}

void backtracking() {
    if (order.size() == 5) {
        int s = 0; // 현재 이동방법에서 가장 큰 블록값 저장
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s = max(s, v[i][j]);
            }
        }

        score = max(s, score);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        vector<vector<int>> tmp = v; // 새로 이동하기 전의 2048판 형태 저장
        Move(i);
        order.push_back(i);

        backtracking();

        order.pop_back();
        v = tmp; // 이동정보를 지울 때 원래의 판 형태로 복구
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    backtracking();

    cout << score;
}