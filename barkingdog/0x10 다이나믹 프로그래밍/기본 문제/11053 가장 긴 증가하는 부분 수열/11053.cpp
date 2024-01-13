/*
DP를 사용해 전체 구간의 증가 부분 수열의 길이 중 가장 큰 것을 구하는 것을, 구간을 나눠서 풀이

dp 배열은 해당 수까지 포함한 증가 부분 수열 중에서 가장 길이가 큰 것을 담고 있다.
처음에 dp 배열을 길이가 모두 1이라고 채워넣고, 각 수를 읽을 때마다 이전의 dp 결과를 읽어서
이전 수열에 포함될 수 있을 때(a[j] < a[i]), 이전에 구해놓은 증가 부분 수열의 길이 보다 더 큰지 확인한다(dp[i] < dp[j] + 1)

시간복잡도는 O(n^2) 이다.

해당 문제는 LIS(최장 길이 부분 증가 수열) 라는 문제로 널리 알려진 DP 문제이다.

참고: https://m.blog.naver.com/occidere/220793914361
*/

#include <bits/stdc++.h>
using namespace std;

int a[1004];
int dp[1004];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    dp[i] = 1;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(a[j] < a[i]) {
        if(dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }
  cout << *max_element(dp, dp+n);
  return 0;
}