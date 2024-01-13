/*
dp 문제로 단골인 task scheduling problem 중 하나이다.

전체 문제는 퇴사일 전까지(N일 까지)의 최대 수익을 구하는 것이다.
부분 문제를 구하면, "i일이 끝났을 때의 최대 수익"으로 나눌 수 있다.
이를 dp[i] 라고 하자. i일에 끝나는 일정이 여러개 있다면, 그 일정이 시작하기 전 일을 j라고 했을 때
dp[j]와 현재 일정들을 더한 값을 비교해서 최대값을 찾으면 된다.

시간복잡도는 O(N)이다.

# 만약 14501 퇴사 문제를 그대로 제출했는데 틀렸다면, 아래처럼 다른 dp 식을 떠올리지 못해서일수도 있다.
전체 문제에 대한 최적 부분 문제(dp 식)은 다양할 수 있다. 
O(N^2)으로 부분 문제를 나눌 수도 있지만,
무려 O(N) 으로도 부분 문제를 나눌 수도 있다!
같은 문제라도 다른 DP 식이 나올 수 있음에 유의하자!
'2579 계단 오르기' 문제를 풀어보도록. 정말 다양한 dp 식이 나올 수 있다.
# 처음에 mx의 초기값을 -1로 했었는데, 그렇게 되면 현재 스케쥴을 포함하는 것보다
그냥 dp[i-1](현재 끝난 스케쥴을 포함하지 않고 이전 일의 값을 그대로 가져옴)
일 때가 더 큰 경우를 처리하지 못한다.
최소값을 -1로 처리하는게 맞는지 고민해보자. 사실 별로 좋은 습관은 아닌 것 같다.
*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1600000
#define T first
#define P second

int dp[SIZE]; // i일이 끝났을 때의 최대 수익
vector<pair<int, int>> etp[SIZE];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    int t, p;
    cin >> t >> p;
    int ended = i + t - 1;
    etp[ended].push_back({t, p});
  }
  dp[0] = 0;
  for(int i=1; i<=n; i++) {
    if(etp[i].empty()) {
      dp[i] = dp[i-1];
      continue;
    }
    int mx = dp[i-1]; // 주의! i-1 일이 더 최대 수익을 낼 수도 있다. 초기값을 -1로 주면 안된다.
    for(auto e : etp[i]) {
      mx = max(dp[i - e.T] + e.P, mx);
    }
    dp[i] = mx;
  }
  cout << dp[n];
  return 0;
}