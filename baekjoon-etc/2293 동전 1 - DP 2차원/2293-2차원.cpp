/*
동전들의 가치의 합이 k인 경우의 수를 "i까지의 동전이 있을 때 가치의 합이 j 인 경우의 수"를 통해 쌓아올려서 푸는 dp 문제.

메모리 초과를 해결하기 위해 홀, 짝인 경우를 나누어서 값을 누적해갔다.
바로 직전 항만 기억하면 되기 때문이다.
*/

#include <bits/stdc++.h>
using namespace std;

int coin[101];
int dp[2][10001]; // 짝 0 홀 1 에 저장

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
            dp[i%2][j] = 0;
            for(int p=0; p<=j; p+=coin[i]) {
                dp[i%2][j] += dp[(i-1)%2][j-p];
            }
            if(j % coin[i] == 0) dp[i%2][j]++;
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=k; j++) {
    //         cout << "i: " << i << ' ' << "j: " << j << ' ' << dp[i][j] << '\n';
    //     }
    // }
    // cout << '\n';
    // cout << dp[1][10] << '\n';
    // cout << dp[2][10] << '\n';
    // cout << dp[3][10] << '\n';
    cout << dp[n%2][k];
	return 0;
}