#include <bits/stdc++.h>

using namespace std;

int w[102];
int v[102];
int dp[101][100001]; // 물건 i 까지 담을 수 있을 때, 최대 무게가 j 일때의 최대 가치

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }
    // i=0 일때는 아무 물건도 없으므로 모든 최대 가치는 0 이다.
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            int mx = dp[i][j-1]; // 최대 무게가 j-1 때의 최대 가치와
            if(j - w[i] >= 0) mx = max(mx, v[i] + dp[i-1][j-w[i]]); // 현재 물건 i 를 포함하고 물건 i를 포함하지 않았을 때 물건 i의 무게를 제외한 최대 가치와
            if(i > 0) mx = max(mx, dp[i-1][j]); // 물건 i를 아예 포함하지 않을 때의 최대 가치를 비교한다.
            dp[i][j] = mx;
        }
    }
    cout << dp[n][k];
    return 0;
}