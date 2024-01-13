/*
정렬과 그리디를 이용해서 풀 수 있는 문제.

밧줄을 선택하는 모든 경우의 수를 구하고 버틸 수 있는 최대 무게를 구한다면 O(2^N)은 족히 나올 것이다.
하지만 그리디로 풀 경우 훨씬 간단하게 풀이가 된다.
직관적으로, N개의 밧줄 중에서 몇 개의 밧줄을 뽑았을 때 이들이 버틸 수 있는 최대 무게는 최대 무게가 가장 작은 밧줄에 좌우된다는 것을 생각할 수 있다.
이에 따라 밧줄을 버틸 수 있는 무게 순으로 정렬하고,
rope[n-i] * i 의 최대값을 구하면 된다는 것을 알 수 있다.
해당 풀이를 통해, 정렬비용 O(NlgN) 과 탐색비용 O(N), 즉 O(NlgN) 안에 문제를 풀 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int rope[100001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> rope[i];
  }
  sort(rope, rope + n, greater<>());
  int mx = 0;
  for(int i=0; i<n; i++) {
    int cur = rope[i] * (i+1);
    mx = max(mx, cur); 
  }
  cout << mx;
  return 0;
}