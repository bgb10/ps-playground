/*
컴퓨터를 노드, 신뢰하는 관계를 단방향 간선이라고 추상화해서 풀면 된다.
연결 요소의 개수가 가장 많은 노드들을 찾으면 된다.

풀이에서는 탐색 방법으로 DFS를 사용했다.
시간복잡도는 O(V(V+E+V)) 이다.

# 연결 요소의 개수를 찾는 문제이기 때문에 DFS를 사용한 것이지,
거리를 구하는 문제같은 경우 DFS로 풀기 힘들다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[10002];
int computer_connected[10002];
bool vis[10002];

int dfs(int cur) {
    vis[cur] = 1;
    int cnt = 1;
    for (int nxt : adjs[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        cnt += dfs(nxt);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        adjs[u].push_back(v);
    }
    int mx_connected = 0;
    for (int v = 1; v <= n; v++) {
        fill(vis, vis + n + 1, 0);
        int cnt = dfs(v);
        computer_connected[v] = cnt;
        mx_connected = max(mx_connected, cnt);
    }
    for (int v = 1; v <= n; v++) {
        if (computer_connected[v] == mx_connected) {
            cout << v << ' ';
        }
    }
    return 0;
}