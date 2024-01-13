// nCr = n! / r!(n-r)! 정의 사용

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int res = 1;
  for(int i=n; i>=1; i--) {
    res *= i;
  }
  for(int i=k; i>=1; i--) {
    res /= i;
  }
  for(int i=n-k; i>=1; i--) {
    res /= i;
  }
  cout << res;
  return 0;
}