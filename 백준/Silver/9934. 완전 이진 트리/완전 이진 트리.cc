#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Func(vector<vector<int>>& tree, vector<int>& order, int left, int right, int height) {
    if (left > right) return;

    int root = (left + right) / 2; // 현재 서브트리의 root는 해당 서브트리의 중위순회 결과의 가운데 
    tree[height].push_back(order[root]); // 이차원벡터에서 index가 낮을수록 가장 위에 위차함

    Func(tree, order, left, root - 1, height + 1); // 현재 서브트리의 왼쪽 자식트리는 root를 기준으로 왼쪽
    Func(tree, order, root + 1, right, height + 1); // 현재 서브트리의 오른쪽 자식트리는 root를 기준으로 오른쪽
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    vector<vector<int>> tree(k);

    int size = pow(2, k) - 1;
    vector<int> order(size + 1);
    for (int i = 1; i <= size; i++) cin >> order[i]; // 입력으로 주어지는 값은 해당 트리의 중위순회 결과
    // 완전이진트리에서 중위순회 결과를 가지고 트리를 복원하기 위한 함수
    Func(tree, order, 1, size, 0);

    for (int i = 0; i < k; i++) {
        for (int x : tree[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}