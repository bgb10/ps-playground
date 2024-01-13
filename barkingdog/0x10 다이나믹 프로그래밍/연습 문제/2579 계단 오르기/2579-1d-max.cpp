/*
2차원 dp 테이블을 역발상을 통해 1차원으로 풀이

dp[i]: i 번째 계단을 반드시 밟았을 때의 최대 계단합
점화식: dp[i] = max(dp[i-2], dp[i-3] + a[i-1]) + a[i];
초항: dp[0] = 0, dp[1] = a[1], dp[2] = a[1] + a[2];

# 역발상을 통한 문제 해결
# 예시를 그려보면서 문제를 풀면 더 쉽게 풀 수 있다.
# 관점에 따라 dp 풀이를 달리할 수 있다!
*/

#include <bits/stdc++.h>
using namespace std;

int a[304];
int dp[304];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	for(int i=3; i<=n; i++) {
		dp[i] = max(dp[i-2], dp[i-3] + a[i-1]) + a[i];
	}
	cout << dp[n];
	return 0;
}