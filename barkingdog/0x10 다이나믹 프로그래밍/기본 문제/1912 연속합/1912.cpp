/*
dp 를 사용해 전체 구간의 최대 연속합을 구하는 문제를, 내가 쪼갠 작은 구간의 최대 연속합을 구하는 문제로
치환해서 풀면 된다.

dp[k] : k 번째까지 수를 읽었을 때 최대 연속합
만약 이전 항의 연속합이 음수일 경우, 해당 연속합을 이어주지 않는다.
양수일 경우에는 더 긴 합을 만들 수 있으므로 이어준다.
전체 문제: N까지 읽었을 때의 최대 연속합
부분 문제: i까지 읽었을 때의 최대 연속합
dp[i] = a[i] (dp[i-1] <= 0)
dp[i] = dp[i-1] + a[i] (dp[i-1] > 0)
*/

#include <bits/stdc++.h>
using namespace std;

int a[100004];
int dp[100004];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  dp[0] = a[0];
  for(int i=1; i<n; i++) {
    if(dp[i-1] > 0) dp[i] = a[i] + dp[i-1];
    else dp[i] = a[i];
  }
  cout << *max_element(dp, dp+n);
  return 0;
}