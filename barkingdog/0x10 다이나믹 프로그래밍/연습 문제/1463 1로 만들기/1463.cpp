#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int D[1000001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  D[1] = 0;
  for(int i=2; i<=1000000; i++) {
    D[i] = min({
      (i % 3) ? INT_MAX : D[i / 3] + 1,
      (i % 2) ? INT_MAX : D[i / 2] + 1,
      D[i-1] + 1
    });
  }
  cout << D[n];
  return 0;
}