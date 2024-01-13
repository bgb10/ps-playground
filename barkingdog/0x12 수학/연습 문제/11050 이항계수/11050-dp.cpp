#include <bits/stdc++.h>
#define DIV 10007
using namespace std;

int C[1001][1001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i=1; i<=n; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    C[i][1] = i;
  }
  for(int i=1; i<=k; i++) {
    for(int j=2; j<=n; j++) {
      C[j][i] = ((C[j-1][i-1] % DIV) + (C[j-1][i] % DIV)) % DIV;
    }
  }
  cout << C[n][k];
  return 0;
}