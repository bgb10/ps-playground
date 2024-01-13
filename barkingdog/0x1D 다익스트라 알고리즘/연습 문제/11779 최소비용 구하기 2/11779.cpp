/*

*/
#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adjs[1005];

int n, m;

int d[1005];
int pre[1005];

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
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pre[nxt.Y] = cur.Y;
            PQ.push({d[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adjs[u].push_back({c, v});
    }
    int st, en;
    cin >> st >> en;
    dijkstra(st);
    int cur = en;
    vector<int> route;
    while (cur != st) {
        route.push_back(cur);
        cur = pre[cur];
    }
    route.push_back(st);
    cout << d[en] << '\n';
    cout << route.size() << '\n';
    for (auto it = route.rbegin(); it != route.rend(); it++) {
        cout << *it << ' ';
    }
    return 0;
}