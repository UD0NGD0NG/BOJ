#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char c;
    int t, n, i, flag, head;
    string p, arr, s, trash;
       
    cin >> t;
    while (t--) {
        flag = 1, head = 1, s = "";
        deque<int> dq;
        cin >> p >> n; // 수행할 함수, 배열의 크기
        
        while (dq.size() != n) { // 배열의 크기가 채워질때까지 입력받기
            cin >> c;
            if (0 <= c - '0' && c - '0' <= 9) {
                s.push_back(c); // 입력이 숫자인 경우 문자열로 수를 구성 후
            }
            else if (c == ',' || c == ']') {
                dq.push_back(stoi(s)); // 문자열을 수로 바꿔 배열에 넣어주기
                s = "";
            }
        }
        if (!n)
            cin >> trash; // n이 0인경우 입력으로 들어오는 []를 무시하기 위함

        for (i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                head = !head; // 1 -> 0 || 0 -> 1 (1: 앞, 0: 뒤)
            }
            else { // p[i] == 'D'
                if (dq.size()) { // 삭제할 값이 있는경우
                    if (head) dq.pop_front();
                    else dq.pop_back();
                }
                else { // 없는경우
                    flag = 0;
                    break;
                }
            }
        }

        if (dq.empty() && flag) // 함수를 모두 수행한 결과가 빈 배열인 경우
            flag = 2;
        
        if (flag == 1) {
            i = 0;
            cout << '[';
            if (head) { // head가 1인 경우 앞에서부터 출력
                for (i = 0; i < dq.size() - 1; i++) cout << dq[i] << ',';
            }
            else { // head가 0인 경우 뒤에서부터 출력
                for (i = dq.size() - 1; i > 0; i--) cout << dq[i] << ',';
            }
            cout << dq[i] << "]\n";
        }
        else if (flag == 2)
            cout << "[]\n";
        else // flag == 0
            cout << "error\n";
    }
}