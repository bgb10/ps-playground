/*
DP로 푸는 문제.

i번째까지의 최대값을 i-1 번째까지의 최대값을 이용해 풀 수 있다.
dp[현재 포도주][연속으로 마신 횟수]: 현재 포도주에 대해 몇 번 연속으로 마셨을 때 최대 시식량 
으로 정의하고,
만약 i 번째에 포도주를 2번 연속으로 마신다고 하면, i-1 번째에서는 1번 연속으로 마셨을 것이다.
i 번째에 1번 연속으로 마신다고 하면, i-1 번째에서는 마시지 않았을 것이다.
i 번째에 0번 연속으로 마신다고 하면, i-1 번째에서 마시지 않았거나, 1번 연속으로 마셨거나, 2번 연속으로 마신 경우 중
최대값을 사용하면 될 것이다. 

# 전형적인 유형의 DP 문제이다. 2579 계단 오르기 문제와 유사.
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int dp[10002][3];
int grape[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> grape[i];
    }
    dp[0][0] = 0, dp[0][1] = grape[0], dp[0][2] = 0;
    for(int i=1; i<n; i++) {
        dp[i][2] = dp[i-1][1] + grape[i];
        dp[i][1] = dp[i-1][0] + grape[i];
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    return 0;
}