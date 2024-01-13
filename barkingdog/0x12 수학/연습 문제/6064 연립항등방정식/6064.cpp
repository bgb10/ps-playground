#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { // 최대 40000^2 니 int 안에 해결 가능
  return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y) {
  int l = lcm(m, n);
  if(x == m) x = 0;
  if(y == n) y = 0;
  int cnt = 0;
  // 여기서는 1부터 lcm(m, n) 까지 탐색. 시간초과
  for(int i=1; i<=l; i++) {
    if(i % m == x && i % n == y) {
      return i;
    }
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  int m, n, x, y;
  for(int i=0; i<k; i++) {
    cin >> m >> n >> x >> y;
    cout << solve(m, n, x, y) << '\n';
  }
  return 0;
}