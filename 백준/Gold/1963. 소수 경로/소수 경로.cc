#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void Prime(vector<int>& v) { // 에라토스테네스의 체
    v[0] = 0; v[1] = 0;
    for (int i = 2; i < v.size(); i++) {
        if (v[i]) {
            for (int j = 2; i * j < v.size(); j++) {
                v[i * j] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v(10000);
    for (int i = 1; i < 10000; i++) {
        v[i] = i;
    }
    Prime(v);

    int t; cin >> t;
    while (t--) {
        queue<int> q;
        vector<int> dist(10000, 0);

        int a, b; cin >> a >> b;
        dist[a] = 1; // 첫번째 비밀번호의 변환횟수를 1로 설정
        q.push(a);

        while (!q.empty()) {
            string x = to_string(q.front());
            q.pop();
            for (int i = 1; i < 4; i++) { // 천의자리를 제외한 나머지 자리에 0이 들어간 경우
                string tmp = x;
                tmp[i] = '0';
                int next = stoi(tmp);
                if (v[next] && !dist[next]) { // 바꾼 수가 소수이면서 처음 만들어진 경우
                    dist[next] = dist[stoi(x)] + 1; // 바꾼 수의 변환횟수 = 이전 수의 변환횟수 + 1
                    q.push(next);
                }
            }

            for (char i = '1'; i <= '9'; i++) { // 각 자리의 숫자를 0이 아닌 다른수로 바꾸는 경우
                for (int j = 0; j < 4; j++) {
                    string tmp = x;
                    tmp[j] = i;
                    int next = stoi(tmp);
                    if (v[next] && !dist[next]) {
                        dist[next] = dist[stoi(x)] + 1;
                        q.push(next);
                    }
                }
            }
        }

        if (dist[b]) {
            cout << dist[b] - 1 << '\n'; // dist[a]를 1로 초기화 하였으므로 1을 뺀 후 출력
        }
        else { // dist[b] == 0 인 경우(변경을 통해 b를 만들 수 없는 경우)
            cout << "Impossible\n";
        }
    }
}