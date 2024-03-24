#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string prime;
vector<char> element = { '1', '2', '3', '5', '7', '9' }; // 2이외의 짝수가 들어올 경우 소수가 될 수 없음

bool is_prime(int n) { // 소수판별
    if (n < 2) return false;

    bool flag = true;
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            flag = false;
            break;
        }
    }

    return flag;
}

void backtracking() {
    if (prime.size() == n) { // 길이가 n일 때 소수이면 출력
        if (is_prime(stoi(prime)))
            cout << prime << '\n';
        return;
    }
    for (int i = 0; i < 6; i++) {
        prime.push_back(element[i]);

        if (is_prime(stoi(prime))) // 소수가 아닌경우 오른쪽에 숫자를 추가할 필요 없음
            backtracking();

        prime.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    backtracking();
}