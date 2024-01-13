/*
인접행렬로 BFS 를 구현
각 간선마다 나머지 모든 간선에 대해 인접 여부를 따져야 하기 때문에 O(V^2)이다.
*/

#include <bits/stdc++.h>
using namespace std;

int adj[12][12];
int dist[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist + 10, -1);
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int nxt = 1; nxt <= 10; nxt++) {
            if (adj[cur][nxt] != 1) continue;
            if (dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    return 0;
}