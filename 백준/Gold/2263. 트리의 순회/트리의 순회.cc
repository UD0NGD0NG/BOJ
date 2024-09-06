#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void preorder(const vector<int>& inorder, const vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& inorderIndexMap) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd]; //현재 서브트리의 root는 해당 서브트리의 후위순회 기준 맨 뒤의 노드
    cout << root << ' '; // 전위순회는 현재 트리의 root를 방문후 왼쪽 자식 트리 방문, 오른쪽 자식 트리 방문을 재귀적으로 수행

    // 현재 서브트리의 왼쪽 자식 트리는 중위순회 결과에서 현재 서브트리의 root노드 기준 왼쪽 노드들로 구성됨
    int rootIdx = inorderIndexMap[root];
    int leftSize = rootIdx - inStart;
    // 후위순회 입장에서는 시작부터 leftsize개의 노드가 왼쪽 자식 트리, 그 다음 노드부터 root노드 전까지가 오른쪽 자식 트리
    preorder(inorder, postorder, inStart, rootIdx - 1, postStart, postStart + leftSize - 1, inorderIndexMap); // 왼쪽 자식 트리에서 재귀함수 수행
    preorder(inorder, postorder, rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1, inorderIndexMap); // 오른쪽 자식 트리에서 재귀함수 수행
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> inorder(n);
    for (int i = 0; i < n; ++i) cin >> inorder[i];

    vector<int> postorder(n);
    for (int i = 0; i < n; ++i) cin >> postorder[i];

    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < n; ++i) {
        inorderIndexMap[inorder[i]] = i;
    }

    preorder(inorder, postorder, 0, n - 1, 0, n - 1, inorderIndexMap);
}
