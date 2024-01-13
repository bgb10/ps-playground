/*
f(n) 과 f(n-1) 항의 관계로만 식을 구성하는 것이 불가함. 2X1 블록만 추가할 수 있기 때문.
따라서, f(n)과 f(n-1), f(n-2) 로 식을 구성하면, f(n) = f(n-1) + f(n-2) 인 것을 알 수 있다.
f(n-2) 일 때 경우가 2가지가 나오는 것 같지만, f(n-1) 에 이미 그 경우를 따지므로 1가지만 고려하면 된다.

또한 재귀함수를 DP 로 풀면 O(N) 안에 해결 가능하다.

10007 로 나누는 이유는 항이 전개되다가 범위를 벗어나는 경우를 위해서인데, 
맨 마지막에만 10007로 나누면 이미 overflow 가 발생한 이후이다.
따라서, 배열에 값을 누적할 때마다 10007로 나눈 나머지를 기록하면 된다.
(a+b)%k == (a%k + b%k)%k 이기 때문이다.
*/

#include <bits/stdc++.h>
using namespace std;

long long dp[1003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for(int i=3; i<=n; i++)
    dp[i] = dp[i-1] % 10007 + dp[i-2] % 10007;
  cout << dp[n] % 10007;
  return 0;
}