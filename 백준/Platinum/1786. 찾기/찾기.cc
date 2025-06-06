#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<int> F;
int cnt = 0;
int index[1000003] = {};

void failureFunction(string P) {
	F[0] = 0; // 자기 자신과의 비교는 제외하므로 길이가 1일때는 항상 0일수밖에 없음
	int i = 1; // for pattern index
	int j = 0; // for current index

	while (i < m) {
		if (P[i] == P[j]) { // match
			F[i] = j + 1; // index는 0-based이지만 길이는 1-based이므로 1 증가하여 할당
			i++; j++; // match인 경우 pattern 문자열을 시프트할 필요없이 다음 index 계산을 진행하면 됨
					  // 다음에도 일치하는 경우라면 그대로 j + 1값을 넣어주면 되고
		}
		else if (j > 0) { // 다음에는 miss match인 경우
				j = F[j - 1]; // i는 line 16에서 다음 결과에 상관없이 옮겨줬으므로 j만 판단하면 됨, 이때 miss match가 일어났으니 다음 index를 보는건 의미가 없고 이전 index에 대해 판단(?)
		}
		else { // j == 0, 위의 과정에서 직전 실패함수값을 참조한 결과가 0이었는데 또 miss match가 일어난경우 pattern의 시작부에서 miss match가 일어난 것이므로 일치하는 구역이 존재하지 않음
			F[i] = 0; // 그러므로 0을 넣어준 뒤
			i++; // 다음 index로 이동
		}
	}
}

void KMPMatch(string T, string P) { // Text, Pattern
	failureFunction(P); // calculate failureFunc(P)

	int i = 0; // for text index
	int j = 0; // for pattern index

	while (i < n) { // 모든 Text의 index에 대해 연산 수행
		if (T[i] == P[j]) { // match인 경우
			if (j == m - 1) { // 모든 pattern에 대해 match인 경우
				index[cnt++] = i - j; // T에서의 substring(pattern) 시작 index return
				if (j > 0) {
					j = F[j - 1];
				}
				else {
					j = 0; i++;
				}
			}
			else {
				i++;
				j++;
			}
		}
		else { // miss match인 경우
			if (j > 0) { // 접두사 == 접미사인 부분이 존재하여 처음부터 탐색하지 않아도 되는 경우
				j = F[j - 1];
			}
			else { // j == 0, 다시말해 그냥 처음부터 탐색해야하는 경우
				i++; // like Brute Force
			}
		}
	}
}

int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);

	n = T.size(), m = P.size();
	F.resize(m);

	KMPMatch(T, P);

	cout << cnt;
	if (cnt) {
		cout << '\n';
		for (int i = 0; i < cnt; i++) cout << index[i] + 1 << ' ';
	}
}