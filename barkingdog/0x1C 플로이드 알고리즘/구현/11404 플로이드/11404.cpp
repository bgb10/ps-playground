/*
"모든 도시의 쌍 (A, B) 에 대해 도시 A에서 B로 가는데 필요한 비용의 최소값을 구하시오." 
-> 모든 정점 사이의 최단 거리를 구하는 플로이드-와샬 알고리즘을 구현다는 문제다.

주의할 점은, 방문하지 못하는 점의 경우 가중치가 '무한'으로 표시해야 한다.
시간복잡도는 O(V^3) 이다.

# 오버플로우 조심할 것. INT_MAX 같은 큰 수를 무한으로 표현하면 오버플로우가 날 수 있다.
정점 사이의 최대 거리가 대략 100000 * 100 이므로 근처의 값으로 무한을 표현했다.
*/
#include <bits/stdc++.h>
using namespace std;

int cost[105][105];
int dp[105][105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(cost[a][b] == 0) {
            cost[a][b] = c;
        } 
        else {
            cost[a][b] = min(cost[a][b], c);
        }
    }

    // floyd-warshall algorithm
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            fill(dp[i][j], dp[i][j]+n+1, 200000000);
        }
    }
    // 아무것도 거쳐가지 않을 때의 최단거리
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(cost[i][j] != 0 || i == j) {
                dp[i][j][0] = cost[i][j]; 
            }
        }
    }

    for(int v=1; v<=n; v++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j) {
                    dp[i][j][v] = 0;
                    continue;
                }
                dp[i][j][v] = min(dp[i][j][v-1], dp[i][v][v-1] + dp[v][j][v-1]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dp[i][j][n] == 200000000) cout << 0 << ' ';
            else cout << dp[i][j][n] << ' ';
        }
        cout << '\n';
    }
    return 0;
}