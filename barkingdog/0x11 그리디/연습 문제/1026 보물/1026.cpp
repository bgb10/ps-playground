/*
유명한 재배열 부등식 문제로, 그리디적인 접근으로 해결한다.

조건에서는 A만 재배열 할 수 있다고 했지만, 사실 둘 다 해도 상관없다.(호환과 합성의 원리)
그리디적인 접근으로, 큰 수는 최대한 작은 수끼리 곱해서 최소합을 만들어낼 수 있다.
지금 큰 수에 대해 최적의 답인 가장 작은 수를 곱하는 것으로 해결하는 것이다.(그리디)
*/

#include <bits/stdc++.h>
using namespace std;

int a[52];
int b[52];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  sort(a, a+n, greater<>());
  sort(b, b+n);
  int ans = 0;
  for(int i=0; i<n; i++) {
    ans += a[i] * b[i];
  }
  cout << ans;
  return 0;
}