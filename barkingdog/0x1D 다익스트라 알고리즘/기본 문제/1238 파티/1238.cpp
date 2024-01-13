/*
각 마을을 i 라고 할 때, i -> x 와 x -> i 의 최단 거리의 합 중 최대를 구하면 된다.
각 노드 사이의 거리를 구해야 하기 때문에 다익스트라 알고리즘을 사용한다.
시간복잡도는 O(NElgE) 이다.

# 플로이드-와샬은 O(N^3) 이므로 TLE
*/
#include <bits/stdc++.h>

#include <queue>
#define X first
#define Y second
using namespace std;
const int INF = 0x3f3f3f3f;
const int SIZE = 1005;

vector<pair<int, int>> adjs[SIZE];
int d[SIZE];
int dist[SIZE];

int n, m, x;

void dijkstra(int st) {
    fill(d, d + n + 1, INF);
    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, st});
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        if (cur.X != d[cur.Y]) continue;
        for (auto nxt : adjs[cur.Y]) {
            if (d[nxt.Y] > d[cur.Y] + nxt.X) {
                d[nxt.Y] = d[cur.Y] + nxt.X;
                PQ.push({d[nxt.Y], nxt.Y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adjs[a].push_back({t, b});
    }

    // i -> x
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        dist[i] += d[x];
    }

    // x -> i
    dijkstra(x);
    for (int i = 1; i <= n; i++) {
        dist[i] += d[i];
    }

    cout << *max_element(dist + 1, dist + n + 1);

    return 0;
}