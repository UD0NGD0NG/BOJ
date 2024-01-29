#include <iostream>
#include <vector>
using namespace std;

void PreOrder(vector<vector<int>>& edge, int node) { // 전위연산
	if (node == -1)
		return;
	cout << char(node + 'A'); // 알파벳으로 출력
	PreOrder(edge, edge[node][0]);
	PreOrder(edge, edge[node][1]);
}

void InOrder(vector<vector<int>>& edge, int node) { // 중위연산
	if (node == -1)
		return;
	InOrder(edge, edge[node][0]);
	cout << char(node + 'A');
	InOrder(edge, edge[node][1]);
}

void PostOrder(vector<vector<int>>& edge, int node) { // 후위연산
	if (node == -1)
		return;
	PostOrder(edge, edge[node][0]);
	PostOrder(edge, edge[node][1]);
	cout << char(node + 'A');
}

int main() {
	int n;
	cin >> n;
	char a, b, c;
	vector<vector<int>> edge(n + 1, vector<int>(2, -1)); // 자식이 없는경우를 -1로 설정
	while (n--) {
		cin >> a >> b >> c;
		if (b != '.')
			edge[a - 'A'][0] = b - 'A'; // 알파벳을 정수처리 ('A' == 0)
		if (c != '.')
			edge[a - 'A'][1] = c - 'A';
	}
	PreOrder(edge, 0);
	cout << '\n';
	InOrder(edge, 0);
	cout << '\n';
	PostOrder(edge, 0);
}