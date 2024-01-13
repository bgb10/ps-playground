/*
V개의 마을 E개의 도로... 대놓고 그래프 문제라고 준다.
사이클의 최소 길이를 구하는 문제인데, 이는 그냥 a -> b, b -> a 의 최소길이를 구하는 것과 같다.
모든 노드 사이의 거리를 구해야 하므로 플로이드-와샬 알고리즘을 사용하였다.

# 돌아오는 길까지 고려해서 더해줄 경우 int 범위를 벗어날 수 있기에, long long 사용하자.
# 한 마을에서 나와서 바로 들어갈 수 있다. 혹시 모르니 그런 경우도 고려하자.
*/
#include <bits/stdc++.h>

#include <climits>
using namespace std;

using ll = long long;

const ll INF = LONG_LONG_MAX / 5;

ll dp[405][405];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    for (int i = 0; i <= v; i++) {
        fill(dp[i], dp[i] + v + 1, INF);
    }
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        dp[a][b] = cost;
    }
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    ll mn = INF;
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            if (k != i)
                mn = min(mn, dp[i][k] + dp[k][i]);
            else
                mn = min(mn, dp[k][i]);
        }
    }
    if (mn == INF)
        cout << -1;
    else
        cout << mn;
    return 0;
}