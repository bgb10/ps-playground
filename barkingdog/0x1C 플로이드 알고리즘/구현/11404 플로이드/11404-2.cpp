/*
# 1번 풀이에서 3차원 배열 대신 2차원 배열로 저장했다. 
dp 배열에 값이 누적되면서 이전에 계산한 값은 필요가 없기 때문이다.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + n + 1, INF);
    }
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    // floyd-warshall algorithm
    for (int v = 1; v <= n; v++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[v][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == INF)
                cout << '0' << ' ';
            else
                cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}