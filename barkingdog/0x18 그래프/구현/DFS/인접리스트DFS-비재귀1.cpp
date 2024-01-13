/*
BFS 에서 방문할 노드를 저장하는 자료구조만 스택으로 바꾸면 된다.

현재 비재귀1의 구현을 잘 살펴보자.
재귀로 DFS 를 구현하는 경우 방문 체크를 해당 노드에 도착해서 하는 반면,
스택(비재귀)으로 DFS 를 구현하는 경우 방문 체크를 방문 전에 한다.
재귀로 DFS 를 하는 것은 우리가 관념적으로 생각하는 DFS 방식과 일치하나,
스택으로 DFS 를 구현하면 실제 방문 전에 방문 표시를 하기 때문에 살짝 다르다.
# 따라서, Flood Fill 이나 단순 순회가 아니고 DFS 의 성질을 이용해 문제를 해결해야
하는 경우, 아래처럼 코드를 짜면 안된다.

방문순서: 1 2 3 4
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
    vis[1] = 1;
    cout << 1 << ' ';
    S.push(1);
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        for (int nxt : adjs[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = 1;  // 실제 방문 전에 방문 표시
            cout << nxt << ' ';
            S.push(nxt);
        }
    }
    return 0;
}