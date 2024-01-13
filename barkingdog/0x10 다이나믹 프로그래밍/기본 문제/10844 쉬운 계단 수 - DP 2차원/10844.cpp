/*
다이나믹 프로그래밍 문제.

모든 경우의 수를 다 해보기에는 수가 어마어마하게 커서 불가능하다. 그렇다면 자연스럽게 DP 를 떠올릴 수 있는데,
부분 문제를 "길이가 i인 계단 수" 라고 하자. 이때 어떻게 하면 N인 계단 수를 구할 수 있을까?
예시를 들어보면서 관찰하다보면 부분 문제 사이의 패턴을 관찰할 수 있다.
현재 N 자리가 0이라면, 이전에 나온 수는 1일 수밖에 없다. 그리고 1이라면, 이전에 나온 수는 0 또는 2이다.
이걸 통해 부분 문제 사이의 관계를 유추할 수 있다.

시간복잡도는 O(N * 10) 으로 매우 작다. 브루트포스로 했다면 O(10^N) 의 문제를 O(N * 10) 에 해결했다.

# 예시를 여러 개 들어본 다음 부분 문제 사이의 관계를 관찰하자.
# f(n-1) -> f(n) 을 가는 법을 생각해도 좋지만, f(n)이 어떻게 f(n-1) 로부터 왔는지도 생각해보자.
# Integer Overflow 에 주의하자.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[104][10];

const int MOD = 1000000000;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for(int i=1; i<=9; i++) {
		dp[1][i] = 1;
	}
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			int lv = j - 1;
			int rv = j + 1;
			if(lv >= 0) dp[i][j] += dp[i-1][lv] % MOD;
			if(rv <= 9) dp[i][j] += dp[i-1][rv] % MOD;
			dp[i][j] %= MOD;
		}
	}
	int ans = 0;
	for(int i=0; i<=9; i++) {
		ans = (ans % MOD + dp[n][i] % MOD) % MOD;
	}
	cout << ans % MOD;
	return 0;
}