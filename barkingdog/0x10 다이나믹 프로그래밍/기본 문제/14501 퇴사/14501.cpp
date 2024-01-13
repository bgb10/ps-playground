/*
dp 문제로 단골인 task scheduling problem 중 하나이다.

전체 문제는 퇴사일 전까지(N일 까지)의 최대 수익을 구하는 것이다.
부분 문제를 구하면, "i일의 스케쥴을 반드시 포함할 때 i일 까지의 최대 수익"으로 나눌 수 있다.
이를 dp[i] 라고 했을 때, i일에 있는 스케쥴 전에 있는 일정을 이용해야 하는데,
i일 이전을 j라고 할 때, j일의 상담이 끝나고 난 후라면 여태까지 구한 최대수익과 "j 일까지의 최대수익 + 지금 수익"을 비교하면 된다.

시간복잡도는 O(N^2) 이다.

# N 이 작아서 백트래킹으로도 풀 수 있다.
# LIS 문제랑 비슷하다. 찾아보도록 하자.
*/
#include <bits/stdc++.h>
using namespace std;

int t[17];
int p[17];
int dp[17]; // i일의 상담을 포함한 i일까지의 최대 수익

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> t[i] >> p[i];
    if(i + t[i] - 1 <= n) dp[i] = p[i]; 
    else dp[i] = 0; // 상담이 길어 퇴사일 전에 끝내지 못할 경우 i일의 상담을 포함하지 못하므로 0으로 처리.
  }
  for(int i=1; i<=n; i++) {
    if(dp[i] == 0) continue;
    int mx = dp[i];
    for(int j=1; j<i; j++) {
      if(j + t[j] - 1 < i) { // j 일의 상담이 끝나고 난 후라면
        mx = max(mx, dp[j] + p[i]); // 여태까지 구한 최대수익과 j 일 까지의 최대수익 + 지금 수익을 비교 
      }
    }
    dp[i] = mx;
  }
  cout << *max_element(dp+1, dp+n+1);
  return 0;
}