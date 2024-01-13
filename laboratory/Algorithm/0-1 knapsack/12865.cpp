/*
Greedy 로는 해결이 불가능하고, DP 로 해결 가능한 문제.

0-1 Knapsack 으로 유명한 문제이다.
*/

#include <bits/stdc++.h>

using namespace std;

int w[102];
int v[102];
int dp[102][100002];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> w[i] >> v[i];
    }
    dp[0][0] = 0;
    for(int j=1; j<=k; j++) {
        if(j >= w[0]) dp[0][j] = v[0];
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<=k; j++) {
            if(j == 0) {
                dp[i][j] = 0;
            }
            else if(w[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[n-1][k];
    return 0;
}