/*
최적화 문제를 결정 문제로 바꾸어서 푸는 parametric search(매개 변수 탐색) 문제이다.

적어도 M미터의 나무를 가져가기 위해 절단기의 높이를 최대로 설정하는 문제(최적화 문제)를
절단기의 높이가 h 일때 적어도 M 미터 이상의 나무를 가져갈 수 있는가(결정 문제) 로 치환하면 된다.

따라서, h 를 이분탐색으로 찾아가면서 절단기의 최대 높이를 찾으면 된다.

# 수의 범위가 크므로 이분탐색 등 로그시간으로 최적화할 수 있는지 고민하면 문제를 접근할 때 편할 것이다.
# 최적화 문제인 만큼 parametric search 를 의심하자.
# 이분탐색 탈출 조건에 유의하자. 무한 loop 에 빠질 수 있다.

참고: https://www.crocus.co.kr/1000 (parametric search 설명)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tree[1000004];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> tree[i];
  }
  ll st = 0, en = 1000000000;
  while(st < en) {
    ll mid = (st + en + 1) / 2;
    ll cutted = 0;
    for(int i=0; i<n; i++) {
      cutted += (tree[i] - mid) > 0 ? tree[i] - mid : 0;
    }
    if(cutted >= m) st = mid;
    else en = mid - 1;
  }
  cout << st;
  return 0;
}