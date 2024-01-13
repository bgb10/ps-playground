/*
dp[i]: 수열의 마지막이 i번째 수일 때, 가장 긴 감소하는 부분 수열의 길이
dp[i] = max(dp[j]) + 1; (a[i] < a[j] 이고 j < i 일 때의 모든 j)
dp[i]는 i번째 수가 들어갈 수 있는 수열 중 가장 긴 감소하는 부분 수열의 길이에 1을 더한 것과 같다.

시간복잡도는 O(N^2) 이다.
*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005

int a[SIZE];
int dp[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}