#include <bits/stdc++.h>
using namespace std;

int D[12];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  D[1] = 1, D[2] = 2, D[3] = 4;
  for(int i=4; i<=10; i++) {
    D[i] = D[i-1] + D[i-2] + D[i-3];
  }
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << D[n] << '\n';
  }
  return 0;
}