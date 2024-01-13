/*
1번 노드부터 시작해서 노드 사이의 거리를 구하는 것으로 추상화할 수 있다.

BFS로 구현하였다.
시간복잡도는 O(V+E).
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[20002];
int dist[20002];

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
    int mx_distance = 0;
    fill(dist, dist + n + 1, -1);
    queue<int> Q;
    dist[1] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int nxt : adjs[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
            mx_distance = max(mx_distance, dist[nxt]);
        }
    }
    int to_hide = 0, distance = mx_distance, cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (dist[v] == distance) {
            cnt++;
            if (to_hide == 0) {
                to_hide = v;
            }
        }
    }
    cout << to_hide << ' ' << distance << ' ' << cnt;
    return 0;
}