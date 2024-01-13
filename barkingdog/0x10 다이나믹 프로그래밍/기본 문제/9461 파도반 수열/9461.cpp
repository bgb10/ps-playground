/*
간단한 DP 문제이다. 항 사이의 관계를 관찰하고, 초항을 정한다.
매 테스트케이스마다 재귀함수를 호출하면 계산의 중복이 많이 일어나기 때문에, DP 로 미리 구해놓는다.

# 수열을 나열한 후 항 사이의 관계를 관찰하라.
# 수의 범위에 주의하자. int 벗어날 수도 있다.
*/

#include <bits/stdc++.h>
using namespace std;

long long dp[104];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;
  for(int i=6; i<=100; i++)
    dp[i] = dp[i-1] + dp[i-5];
  int t;
  cin >> t;
  int n;
  while(t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}