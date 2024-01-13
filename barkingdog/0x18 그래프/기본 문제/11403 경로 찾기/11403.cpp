/*
각 노드마다 모든 연결 노드들에 대해 탐색(BFS) 를 진행해서 경로가 있는지, 없는지 구할 수 있다.

일반적으로 방문 체크를 할 때 이전 노드들이 방문했던 흔적을 지우지만,
시간복잡도를 줄이기 위해 각 노드를 정할 때마다 그 값을 이용해 방문 체크를 했다.

시간복잡도는 O(N*N^2) = O(N^3) 이다.  (각 노드에 대해 N * 인접 행렬을 이용한 BFS 탐색 N^2)

# 노드에 loop 가 존재하거나 어떤 노드도 연결되지 않는 경우를 주의하자.
i번 노드에서 시작했다고 i번 노드에 방문할 수 있는게 아니다. i번 노드에서 loop로 방문하거나, 다른 노드를 거쳐 방문해야한다.
*/

#include <bits/stdc++.h>
using namespace std;

int adjs[102][102];
int vis[102];  // 방문 노드 체크
int ans[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adjs[i][j];
        }
    }
    // BFS (1번 노드부터 N번 노드까지)
    for (int u = 1; u <= n; u++) {
        queue<int> Q;
        Q.push(u);
        // vis[u] = u;
        while (!Q.empty()) {
            int from = Q.front();
            Q.pop();
            for (int to = 1; to <= n; to++) {
                // if (from == to) continue; loop 가 있는 경우를 고려하자.
                if (adjs[from][to] == 0) continue;
                if (vis[to] == u) continue;
                Q.push(to);
                vis[to] = u;
                ans[u][to] = 1;
            }
        }
        for (int v = 1; v <= n; v++) {
            cout << ans[u][v] << ' ';
        }
        cout << '\n';
    }
    return 0;
}