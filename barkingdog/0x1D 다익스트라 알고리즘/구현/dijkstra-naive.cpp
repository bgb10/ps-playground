/*
O(V^2 + E) 의 다익스트라 알고리즘이다.
1) 매 순간의 최소 거리 정점을 구하고, 2) 거리를 갱신하는 방향으로 알고리즘이 진행된다.
한 정점에서 다른 모든 정점까지의 거리를 구할 수 있다.

# 해당 구현은 1950년대에 나온 것으로, 수학적으로 최적화할 수 있다.
지금은 이렇게 구현하지 않는다.
*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 20005
#define X first   // 거리
#define Y second  // 정점
#define INF 0x3f3f3f3f

vector<pair<int, int>> adj[20005];
bool fix[SIZE];
int d[SIZE];
int n = 10;

void dijkstra_naive(int st) {
    fill(d, d + n + 1, INF);
    d[st] = 0;
    while (1) {
        // 최소 거리 정점 구하기
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            if (fix[i]) continue;
            if (idx == -1)
                idx = i;
            else if (d[i] < d[idx])
                idx = i;
        }
        // 더 이상 선택할 정점이 없다면
        if (idx == -1 || d[idx] == INF) {
            break;
        }
        fix[idx] = 1;  // 정점 idx 고정
        // 거리 갱신
        for (auto nxt : adj[idx]) {
            d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}