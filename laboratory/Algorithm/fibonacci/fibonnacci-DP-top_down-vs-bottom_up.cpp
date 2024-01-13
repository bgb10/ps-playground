#include <bits/stdc++.h>
using namespace std;

int n;

/*
작은 문제부터 시작해서 작은 문제를 점점 쌓아 큰 문제를 푸는 Bottom - up 방식
첫번째 수와 두 번째 수를 넣어 놓고 하나씩 쌓아 올라가면 됨.
# 보통 다이나믹 프로그래밍은 '상향식 방법'을 의미
*/
int dp[50];
int fibonacci_bottom_up(int n) {
  dp[1] = dp[2] = 1;
  for(int i=3; i<50; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

/*
큰 문제부터 작은 문제로 분할해가면서 푸는 Top - down 방식
이전에 구했던 것을 memoize 해서 다시 계산하지 않도록 함.
*/
int memo[50];
int fibonacci_top_down(int n) {
  if(n <= 2)
    return 1;
  if(memo[n] != 0) 
    return memo[n];
  else
    return memo[n] = fibonacci_top_down(n-1) + fibonacci_top_down(n-2); // 큰 문제에서 작은 문제로 분할
}

int main()
{
  cin >> n;
  cout << fibonacci_bottom_up(n) << '\n';
  cout << fibonacci_top_down(n) << '\n'; // 메모이제이션 사용
  return 0;
}