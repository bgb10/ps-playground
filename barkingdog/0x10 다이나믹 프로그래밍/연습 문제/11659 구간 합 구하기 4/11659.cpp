// prefix algorithm (구간 합 알고리즘) 을 이용한 풀이. 구간 합을 미리 구해놓고, 구간의 차를 이용해 구간 합을 구할 수 있다.

#include <bits/stdc++.h>
using namespace std;

int s[100001];
long long dp[100001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    cin >> s[i];
  dp[1] = s[1];
  for(int i=2; i<=100000; i++)
    dp[i] = dp[i-1] + s[i];
  int a, b;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    cout << dp[b] - dp[a-1] << '\n';
  }
  return 0;
}