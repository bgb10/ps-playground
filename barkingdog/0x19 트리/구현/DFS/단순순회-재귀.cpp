/*
부모 노드에 대한 기록 없이 단순히 재귀만 할 때는 코드가 훨씬 깔끔해진다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];

void dfs(int cur, int par) {
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
        if (par == nxt) continue;  // 부모 노드가 다음 방문할 노드일 경우 제외
        dfs(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}