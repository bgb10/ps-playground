/*
주어진 시작점에서 다른 모든 정점으로의 최단 경로 구하기 -> 다익스트라 알고리즘
V가 20000 이고 E가 300000 이기 때문에 O(V^2 + E) 인 다익스트라로 구현하면 TLE가 난다.
우선순위 큐를 사용한 O(ElgE) 짜리로 구현해야 함.
*/
#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define SIZE 20005
const int INF = 0x3f3f3f3f;
#define X first   // 거리
#define Y second  // 정점 번호

int d[SIZE];
vector<pair<int, int>> adjs[SIZE];
int v, e, k;

void dijkstra(int st) {
    fill(d, d + v + 1, INF);
    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({d[st], st});
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        if (cur.X != d[cur.Y]) continue;
        for (auto nxt : adjs[cur.Y]) {
            // 현재 기록된 거리 vs 현재 노드를 거쳤다가 다음 노드를 가는 거리
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            PQ.push({d[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    cin >> k;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjs[u].push_back({w, v});
    }
    dijkstra(k);
    for (int i = 1; i <= v; i++) {
        if (d[i] == INF)
            cout << "INF";
        else
            cout << d[i];
        cout << '\n';
    }
    return 0;
}