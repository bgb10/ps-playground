/*
DP를 사용해 전체 구간의 증가 부분 수열의 합 중 가장 큰 것을 구하는 것을, 구간을 나눠서 풀이

수의 범위가 정해져 있다는 것을 관찰하고 역인덱스 방식(수의 크기가 곧 배열의 인덱스)를 사용했다.
dp 배열은 해당 수까지 포함한 증가 부분 수열 중에서 가장 합이 큰 것을 담고 있다.
따라서, a[i] = k 라고 할 때, dp[k] = max(dp[1] ~ dp[k-1]) 이 성립한다.

시간복잡도는 O(n * 1000) 이다.

# 잘 이해가 안간다면 예제 입력을 그려서 하나씩 따라해보자.
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
  }
  dp[a[0]] = a[0];
  for(int i=1; i<n; i++) {
    int mx = 0;
    mx = *max_element(dp, dp+a[i]);
    dp[a[i]] = mx + a[i];
  }
  int ans = 0;
  for(int i=0; i<=1000; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}