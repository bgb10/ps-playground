/*
비재귀2에서 level 이 같은 노드들 중 번호가 낮게 매겨진 노드들부터 방문하도록
인접 리스트에 있는 노드들을 stack 에 넣을 때 반대 순서로 넣어준다.

방문순서: 1 2 4 3
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[10];
bool vis[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    adjs[1] = {2, 3, 4};
    adjs[2] = {1, 4};
    adjs[3] = {1, 4};
    adjs[4] = {1, 2, 3};
    stack<int> S;
    S.push(1);
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;  // 실제 방문 후 방문 표시
        cout << cur << ' ';
        for (int i = adjs[cur].size() - 1; i >= 0; i--) {
            if (vis[adjs[cur][i]]) continue;
            S.push(adjs[cur][i]);
        }
    }
    return 0;
}