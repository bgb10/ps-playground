/*

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  int end = 1;
  for(int i=0; i<m; i++) end *= n; // 이러면 시간복잡도가 터질 수밖에 없는데.... O(N^M) 이다.
  long long ans = 0;
  for(int i=0; i<end; i++) {
    int temp = i;
    int sum = 0;
    for(int j=0; j<m; j++) {
      int c = temp % n;
      sum += c + 1;
      temp /= n;
    }
    if(sum <= k) ans = (ans + 1) % 998244353;
  }
  cout << ans % 998244353;
  return 0;
}