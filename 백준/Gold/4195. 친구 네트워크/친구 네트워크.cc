#include <iostream>
#include <vector>
#include <map>
using namespace std;

int Find(vector<int>& uf, int node) {
    if (uf[node] == node) return node;

    int root = Find(uf, uf[node]);
    uf[node] = root;
    return root;
}

void Union(vector<int>& uf, int node1, int node2) {
    int root1 = Find(uf, uf[node1]), root2 = Find(uf, uf[node2]);

    uf[root1] = root2;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while (t--) {
        vector<int> uf(1, 0);
        map<string, int> mp;
        vector<int> relation(200001, 0);
        int f; cin >> f;

        while (f--) {
            string f1, f2; cin >> f1 >> f2;
            int r = 0; // 새로 생긴 친구 수
            if (mp.find(f1) == mp.end()) {
                mp[f1] = mp.size() + 1; // 새로운 사람이라면 해당 사람의 번호를 매겨주고
                uf.push_back(mp[f1]); // union-find를 위한 배열에 자기자신이 root인 상태로 추가
                r++;
            }
            if (mp.find(f2) == mp.end()) {
                mp[f2] = mp.size() + 1;
                uf.push_back(mp[f2]);
                r++;
            }


            if (Find(uf, mp[f1]) != Find(uf, mp[f2])) { // 아직 모르는 사이라면
                int tmp1 = relation[Find(uf, mp[f1])], tmp2 = relation[Find(uf, mp[f2])]; // 합치기 전의 각자 친구수를 저장 후

                Union(uf, mp[f1], mp[f2]);

                relation[Find(uf, mp[f1])] = tmp1 + tmp2 + r; // 각자의 친구수의 합에 새로 생긴 친구수를 더해줌
            }

            cout << relation[Find(uf, mp[f1])] << '\n';
        }
    }
}