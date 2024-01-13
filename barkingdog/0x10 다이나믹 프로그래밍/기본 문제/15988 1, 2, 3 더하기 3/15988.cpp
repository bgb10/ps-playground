/*
dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

수가 INT를 훌쩍 넘을 수 있기 때문에,
(a + b) % MOD = (a % MOD + b % MOD) % MOD 성질을 잘 활용하자.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1000004];
const int MOD = 1000000009;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = ((dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD + dp[i - 3] % MOD) % MOD;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}