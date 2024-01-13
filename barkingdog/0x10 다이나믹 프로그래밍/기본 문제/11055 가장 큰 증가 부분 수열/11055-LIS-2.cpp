/*
전체 문제: 수열에 대한 최대 증가 부분 수열합
부분 문제(dp 정의): i 번째까지의 최대 증가 부분 수열합.

각 항에 대해 최대 증가 부분 수열합이 계산되어 있다고 가정하고, 
dp[i] = dp[j] + a[i] 이다. (a[j] < a[i] 이고, dp[i] < dp[j] + a[i] 일때)
이전에 계산한 최대 증가 부분 수열합을 사용해, 다음 항의 최대 증가 부분 수열합을 구할 수 있다!
*/

#include <bits/stdc++.h>
using namespace std;

int a[1004];
int dp[1004];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(dp[i] < dp[j] + a[i]) {
                    dp[i] = dp[j] + a[i];
                }
            }
        }
    }
    cout << *max_element(dp, dp+n);
	return 0;
}