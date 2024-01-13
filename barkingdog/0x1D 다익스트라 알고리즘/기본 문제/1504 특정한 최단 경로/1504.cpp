/*
1 -> v1 -> v2 -> n 과 n -> v2 -> v1 -> 1 중 최단 길이를 비교하면 된다.
간선 사이의 거리를 구하는 것은 다익스트라 알고리즘으로 해결한다.
*/
#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define X first
#define Y second
const int SIZE = 805;
const int INF = 500000000;

vector<pair<int, int>> adjs[SIZE];

int n, e;
int d[SIZE];

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
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adjs[u].push_back({c, v});
        adjs[v].push_back({c, u});
    }
    int v1, v2;
    cin >> v1 >> v2;
    int ans1 = 0;
    dijkstra(1);
    ans1 += d[v1];
    dijkstra(v1);
    ans1 += d[v2];
    dijkstra(v2);
    ans1 += d[n];
    int ans2 = 0;
    dijkstra(1);
    ans2 += d[v2];
    dijkstra(v2);
    ans2 += d[v1];
    dijkstra(v1);
    ans2 += d[n];
    if (ans1 >= INF && ans2 >= INF) {
        cout << -1;
    } else if (ans1 < ans2) {
        cout << ans1;
    } else {
        cout << ans2;
    }
    return 0;
}