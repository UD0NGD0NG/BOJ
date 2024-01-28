#include <iostream>
#include <vector>
using namespace std;

void PostOrder(int(&tree)[1000000][2], int node) { // 후위 순회
	if (node == -1)
		return;
	PostOrder(tree, tree[node][0]);
	PostOrder(tree, tree[node][1]);
	cout << node << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tree[1000000][2]; // 문제에서의 최대 조건으로 배열 선언
	int x, root = -1, parent, node, i, j;
	for (i = 0; i < 1000000; i++)
		for (j = 0; j < 2; j++)
			tree[i][j] = -1; // 배열의 모든 값을 -1(null)로 초기화
	while (cin >> x) { // EOF입력
		node = root, parent = root;
		while (node != -1) { // 입력받은(삽입할)값의 부모 node가 될 node 찾기
			parent = node;
			if (node > x)
				node = tree[node][0];
			else
				node = tree[node][1];
		}
		if (parent == -1) // root가 없는 경우
			root = x;
		else if (parent > x) // 부모보다 작은값은
			tree[parent][0] = x; // 왼쪽 node에 삽입
		else // 부모보다 큰값은
			tree[parent][1] = x; // 오른쪽 node에 삽입
	}
	PostOrder(tree, root);
}