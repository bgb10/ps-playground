#include <bits/stdc++.h>
using namespace std;

// 정수의 정수승을 계산할 때 pow 함수를 쓰지 말자. pow 함수는 오차를 불러온다.
// pow 함수를 쓰는 대신 정직하게 for문으로 제곱을 돌리자.
// 특별하게, 2 ^ n 을 구현하는 경우 left shift 연산자(<<) 를 사용할 수 있다.

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long p1 = 1; // long long 은 유효자리가 19자리이다.
  for(int i=0; i<38; i++) p1 *= 3;
  long long p2 = 1;
  p2 = pow(3, 38); // pow의 반환형은 double 이고, 유효자리가 15자리이다.
  cout << p1 << '\n' << p2;
  return 0;
}