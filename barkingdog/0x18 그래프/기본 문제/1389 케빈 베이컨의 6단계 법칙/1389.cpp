/*
문제를 해석하면, 무방향 연결 그래프 노드들 사이의 거리가 같고, 최단 경로를 구해야 한다.
따라서 BFS를 여러번 해서 각 노드들 사이의 거리를 구하면 된다.

시간복잡도는 O(N(N+M)) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[102];
int dist[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    int ansmin = INT_MAX;
    int ans = 0;
    for(int u=1; u<=n; u++) {
        fill(dist, dist+102, -1);
        queue<int> Q;
        dist[u] = 0;
        Q.push(u);
        int kbsum = 0;
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for(int nxt : adjs[cur]) {
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                kbsum += dist[nxt];
                Q.push(nxt);
            }
        }
        if(kbsum < ansmin) {
            ansmin = kbsum;
            ans = u;
        }
    }
    cout << ans;
    return 0;
}