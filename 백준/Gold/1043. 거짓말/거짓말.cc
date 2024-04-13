#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>& uf, int node) {
	if (uf[node] == node) return node;

	int root = Find(uf, uf[node]);
	uf[node] = root;
	return root;
}

void Union(vector<int>& uf, int node1, int node2) {
	int root1 = Find(uf, node1), root2 = Find(uf, node2);

	uf[root1] = root2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	vector<int> uf(n + 1); for (int i = 0; i <= n; i++) uf[i] = i;
	vector<vector<int>> party(m);

	int know; cin >> know; // 진실을 아는 사람의 수
	vector<int> truth(know); // 진실을 아는 사람 정보 저장
	for (int i = 0; i < know; i++) cin >> truth[i];

	for (int i = 0; i < m; i++) {
		int cnt; cin >> cnt; // 파티의 인원 수

		int pre = 0;
		for (int j = 0; j < cnt; j++) {
			int num; cin >> num;
			party[i].push_back(num); // 현재 파티의 참석자 저장

			if (pre) { // 이전 사람의 정보가 있다면
				Union(uf, num, pre); // 이전 사람과 현재 사람 아는 사이로 결합
			}

			pre = num; // 지금 들어온 사람의 정보를 이전 사람에 저장
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool flag1 = true; // 현재 파티에서 거짓말을 할 수 있다면 true, 없다면 false

		for (int j = 0; j < know; j++) {
			bool flag2 = false; // 현재 파티에 진실을 아는 사람과 아는 사이인 사람이 있다며 true, 없다면 false
			for (int k = 0; k < party[i].size(); k++) { // 현재 파티의 참석자 중에서
				if (Find(uf, truth[j]) == Find(uf, party[i][k])) { // 진실을 아는 사람과 아는 사이가 있는 경우 
					flag1 = false;
					flag2 = true;
					break;
				}
			}

			if (flag2) break;
		}

		if (flag1) ans++;
	}

	cout << ans;
}