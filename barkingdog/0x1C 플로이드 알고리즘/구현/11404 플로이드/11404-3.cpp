/*
# 2번 풀이에서 대입 시간을 단축하기 위해 비교 후 무조건 대입하는게 아니라,
작을 경우에만 대입하도록 했다. 
n = 100 인 해당 문제에서는 유의미하지 않지만, n=1000 인 경우 200ms 정도 절약할 수 있다.
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
                if(dp[i][j] > dp[i][v] + dp[v][j]) {
                    dp[i][j] = dp[i][v] + dp[v][j];
                }
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