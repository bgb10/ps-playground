/*
DFS(재귀) 를 사용한 연결 요소의 개수 파악

인접 리스트를 사용했으므로 공간복잡도 O(V+E), 시간복잡도 O(V+2E) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[1002];
bool vis[1002];

void dfs(int cur) {
    vis[cur] = 1;
    for (int nxt : adjs[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    int cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (vis[v]) continue;
        cnt++;
        dfs(v);
    }
    cout << cnt;
    return 0;
}