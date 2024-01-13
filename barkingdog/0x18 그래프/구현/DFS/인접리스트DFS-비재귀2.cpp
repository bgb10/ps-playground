/*
비재귀1과는 다르게 방문 체크를 stack 에서 노드를 뽑고 난 직후 한다.

노드별로 방문을 여러번 할 수는 있지만, DFS의 동작방식과 일치한다.
# 이때 재귀 DFS 와는 방문 순서가 약간 다른데,
재귀에서는 배열의 앞에서부터 바로 방문을 하고,
비재귀2에서는 스택에 다 넣어놓고 방문하므로 배열의 뒤에서부터 방문한다.

결국, 비재귀1은 DFS 의 정의와는 다르게 level 이 같은 노드들을 우선 방문해서
일반적인 DFS 와 다르고, 비재귀2와 재귀는 DFS 의 정의와 맞게 level 이 같은
노드들을 우선 방문하는 것으로 생각하면 된다. 하지만 여기서는 level 이 같은
노드들 중 번호가 높게 매겨진 노드부터 방문한다.

방문순서: 1 4 3 2
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
        for (int nxt : adjs[cur]) {
            if (vis[nxt]) continue;
            S.push(nxt);
        }
    }
    return 0;
}