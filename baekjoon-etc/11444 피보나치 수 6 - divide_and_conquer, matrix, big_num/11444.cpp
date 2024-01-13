/*
피보나치 수열을 행렬로 표현한 후, 행렬 곱셈과 분할 정복을 이용해 
시간복잡도를 O(lgN) 으로 줄인 피보나치 수열
N이 대략 1억보다 큰 경우 O(N) 으로 하면 시간초과 및 메모리 초과(메모이제이션 할 배열의 용량)가 나기 때문에,
로그시간으로 줄일 방법을 고민해보면 풀 수 있는 문제다. 

참고: https://jow1025.tistory.com/101
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;

struct M
{
  long long data[2][2];
};

M multiply(M a, M b)
{
	M c;
	c.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0]) % MOD;
	c.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1]) % MOD;
	c.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0]) % MOD;
	c.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1]) % MOD;
	return c;
}

M divide(M a, ll n) {
  if(n == 1) 
    return a;
  
  M divided = divide(a, n/2); // divide (분할)
  a = multiply(divided, divided); // conquer (정복)
  if(n % 2 == 1) {
    M b;
    b.data[0][0] = 1, b.data[0][1] = 1;
		b.data[1][0] = 1, b.data[1][1] = 0;
		//구한 a와 f(1)곱해줌.
    a = multiply(a, b);
  }
  return a;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  M a;
  a.data[0][0] = 1;
  a.data[0][1] = 1;
  a.data[1][0] = 1;
  a.data[1][1] = 0;
  a = divide(a, n);
  cout << a.data[0][1];
  return 0;
}