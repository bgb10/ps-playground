/*
DFS 를 사용한 연결 요소의 개수 파악

인접 리스트를 사용했으므로 공간복잡도 O(V+2E), 시간복잡도 O(V+2E) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[1002];
bool vis[1002];
bool vis2[1002];
int n, m, s;

// 재귀 DFS
void dfs(int cur) {
    vis[cur] = 1;
    cout << cur << ' ';
    for (int nxt : adjs[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adjs[i].begin(), adjs[i].end());
    }
    // 비재귀 DFS
    stack<int> S;
    S.push(s);
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        cout << cur << ' ';
        for (int i = 0; i < adjs[cur].size(); i++) {
            int nxt = adjs[cur][adjs[cur].size() - 1 - i];
            if (vis[nxt]) continue;
            S.push(nxt);
        }
    }
    cout << '\n';
    // BFS
    queue<int> Q;
    vis2[s] = 1;
    cout << s << ' ';
    Q.push(s);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int nxt : adjs[cur]) {
            if (vis2[nxt]) continue;
            vis2[nxt] = 1;
            cout << nxt << ' ';
            Q.push(nxt);
        }
    }
    return 0;
}