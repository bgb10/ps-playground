/*
MST를 구하면 되는 쉬운 문제.

'모든 행성 간에 플로우를 설치' 해야 하고 (연결 그래프),
'제국의 모든 행성을 연결하면서 플로우 관리 비용을 최소한으로 해야 한다.' (모든 노드를 연결하는 최소 비용) 는 것을 보아,
주어진 상황을 그래프로 추상화하고 MST를 구하면 된다.

Prim Algorithm 을 사용하였다. 
(MST에 포함된 노드와 포함되지 않은 노드들을 잇는 간선 중 최소 가중치 간선을 선택해가는 알고리즘)

# 시간복잡도는 O(N^2lgN) 이다. (그래프의 간선 N(N-1)/2 에 대해 우선순위 큐 연산 lgN)
*/
#include <bits/stdc++.h>

#include <queue>
using namespace std;

int adjs[1005][1005];
bool vis[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjs[i][j];
        }
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> to_visit;
    int cnt = 0;
    long long ans = 0;
    vis[0] = 1;
    for (int i = 1; i < n; i++) {
        to_visit.push({adjs[0][i], 0, i});
    }
    while (cnt < n - 1) {
        auto edge = to_visit.top();
        to_visit.pop();
        int cost, a, b;
        tie(cost, a, b) = edge;
        if (vis[b]) continue;
        vis[b] = 1;
        cnt++;
        ans += cost;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            to_visit.push({adjs[b][i], b, i});
        }
    }
    cout << ans;
    return 0;
}