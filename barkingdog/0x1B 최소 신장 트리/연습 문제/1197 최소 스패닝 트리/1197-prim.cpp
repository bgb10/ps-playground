/*
Prim Algorithm 을 이용해 푸는 간단한 문제.

각 간선 E는 우선순위 큐에 최대 1번씩 들어가고, 1번씩 삭제되므로,
시간복잡도는 O(ElgE) 이다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adjs[10005];  // 정점 a -> {비용, 정점 b}
bool is_in_MST[10005];               // 정점 a -> MST 에 포함되는가?

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adjs[b].push_back({cost, a});
        adjs[a].push_back({cost, b});
    }
    // 비용, 정점 a, 정점 b 를 저장하는 최대 힙
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;
    is_in_MST[1] = 1;
    for (auto nxt : adjs[1]) {
        PQ.push({nxt.X, 1, nxt.Y});
    }
    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = PQ.top();
        PQ.pop();
        if (is_in_MST[b]) continue;  // a는 이미 MST에 포함된 정점이기 때문에 b는 포함되면 안됨.
        is_in_MST[b] = 1;
        cnt++;
        ans += cost;
        for (auto nxt : adjs[b]) {
            if (is_in_MST[nxt.Y]) continue;
            PQ.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans;
    return 0;
}