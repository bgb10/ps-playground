/*
트리 내에서는 두 노드 사이의 경로가 단 하나 존재한다(simple path).
따라서, 한 노드에서 DFS 를 통해 다른 노드를 방문하는 방법과 경로, 거리 모두 하나이다.
시작 노드에서 DFS를 돌면서 거리를 누적하다가 도착 노드에 방문했을 경우의 거리를 기록하면 된다.

시간복잡도는 O(NM) 이다.

# 트리의 simple path 성질을 이용하면 최단거리 알고리즘을 사용할 필요가 없는 쉬운 문제이다.
# 가중치가 있다고 DFS, BFS 를 사용하지 못하는 것은 아니다. 상황에 따라 잘 판단하자.
*/
#include <bits/stdc++.h>
using namespace std;
#define N first
#define W second

vector<pair<int, int>> adjs[1002];
bool vis[1002];

int goal = 0;
int ans = 0;

void dfs(int cur, int dist) {
    vis[cur] = 1;
    if(cur == goal) {
        ans = dist;
        return;
    }
    for(auto nxt : adjs[cur]) {
        if(vis[nxt.N]) continue;
        vis[nxt.N] = 1;
        dfs(nxt.N, dist+nxt.W);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adjs[u].push_back({v, d});
        adjs[v].push_back({u, d});
    }
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        goal = v;
        dfs(u, 0);
        cout << ans << '\n';
        fill(vis, vis+n+1, 0);
    }

    return 0;
}