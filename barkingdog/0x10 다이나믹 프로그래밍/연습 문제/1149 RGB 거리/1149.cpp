#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;

int dp[1002][3]; // 거리, 색
int s[1002][3];
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> s[i][0] >> s[i][1] >> s[i][2];
  }
  
  int mn = INT_MAX;
  dp[0][RED] = s[0][RED];
  dp[0][GREEN] = s[0][GREEN];
  dp[0][BLUE] = s[0][BLUE];
  for(int i=1; i<n; i++) {
    for(int color : {RED, GREEN, BLUE}) {
      int nxt1 = (color + 1) % 3;
      int nxt2 = (color + 2) % 3;
      dp[i][color] = min(dp[i-1][nxt1] + s[i][color], dp[i-1][nxt2] + s[i][color]);
    }
  }
  mn = min({dp[n-1][RED], dp[n-1][GREEN], dp[n-1][BLUE]});

  cout << mn;
  return 0;
}