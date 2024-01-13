#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int D[1000001];
int pre[1000001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  D[1] = 0;
  pre[1] = -1;
  for(int i=2; i<=n; i++) {
    D[i] = min({
      (i % 3) ? INT_MAX : D[i / 3] + 1,
      (i % 2) ? INT_MAX : D[i / 2] + 1,
      D[i-1] + 1
    });

    if(!(i % 3) && D[i] == D[i / 3] + 1) {
      pre[i] = i / 3;
    }
    else if(!(i % 2) && D[i] == D[i / 2] + 1) {
      pre[i] = i / 2;
    }
    else {
      pre[i] = i - 1;
    }
  }
  cout << D[n] << '\n';
  int cur = n;
  while(cur != -1) {
    cout << cur << ' ';
    cur = pre[cur];
  }
  return 0;
}