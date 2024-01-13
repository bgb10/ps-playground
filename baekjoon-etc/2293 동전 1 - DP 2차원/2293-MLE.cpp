#include <bits/stdc++.h>
using namespace std;

int coin[101];
int dp[101][10001];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> coin[i];
    }
    sort(coin+1, coin+n+1);
    for(int j=1; j<=k; j++) {
        if(j % coin[1] == 0) dp[1][j] = 1;
    }
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            for(int p=0; p<=j; p+=coin[i]) {
                dp[i][j] += dp[i-1][j-p];
            }
            if(j % coin[i] == 0) dp[i][j]++;
        }
    }
    cout << dp[n][k];
	return 0;
}