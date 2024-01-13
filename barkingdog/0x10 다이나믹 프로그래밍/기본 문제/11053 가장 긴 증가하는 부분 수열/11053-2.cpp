#include <bits/stdc++.h>
using namespace std;

int a[1004];
int dp[1004]; // i 까지의 가장 긴 증가하는 부분 수열

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    cout << *max_element(dp, dp+n);
	return 0;
}