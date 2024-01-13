/*
dp 를 사용해서 풀 수 있는 문제.

마지막 층에 있는 각 원소들 까지의 경로 누적합이 최대가 되는 것이 곧 답이므로, 각 원소들까지의 누적합을 구해야 한다.
지점마다 계속 반복해서 누적합을 구하면 엄청나게 많은 중복이 있고, 이는 dp 로 해결할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[501][501]; // 각 층의 모든 지점들에 대한 최대 누적합
int c[501][501];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<=i; j++) {
      cin >> c[i][j];
    }
  }
  dp[0][0] = c[0][0];
  for(int i=1; i<n; i++) {
    for(int j=0; j<=i; j++) {
      int li = j-1;
      int ri = j;
      int lv = li < 0 ? -1 : dp[i-1][li]; // 왼쪽 끝인 경우 위층의 바로 왼쪽 끝의 누적합을 그대로 가져옴.
      int rv = ri > i-1 ? -1 : dp[i-1][ri]; // 오른쪽 끝인 경우 위층의 바로 왼쪽 끝의 누적합을 그대로 가져옴.
      dp[i][j] = max(lv, rv) + c[i][j];
    }
  }
  vector<int> V;
  for(int i=0; i<n; i++) {
    V.push_back(dp[n-1][i]);
  }
  cout << *max_element(V.begin(), V.end());

  return 0;
}