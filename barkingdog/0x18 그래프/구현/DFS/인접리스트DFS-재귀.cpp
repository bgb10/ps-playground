/*
재귀로 DFS 구현.

함수가 스택 영역에 쌓이기 때문에, 별도의 저장 자료구조를 둘 필요가 없다.
# 온라인 저지 사이트 중에 스택 메모리 제한이 있는 경우 문제가 생길 수도 있다.
그 경우에는 stack 자료구조를 사용할 것.
# 백준, 프로그래머스, 구름은 제한이 없고, SW Expert Academy 에서는 1MB 제한

방문순서: 1 2 4 3
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[10];
bool vis[10];

void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adjs[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    adjs[1] = {2, 3, 4};
    adjs[2] = {1, 4};
    adjs[3] = {1, 4};
    adjs[4] = {1, 2, 3};
    dfs(1);
    return 0;
}