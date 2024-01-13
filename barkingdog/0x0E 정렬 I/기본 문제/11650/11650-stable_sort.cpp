/*
stl 의 stable_sort(merge sort) 를 2번 이용한 풀이.
y 를 기준으로 먼저 정렬하고, x 를 기준으로 정렬한다.
stable_sort 이기 떄문에 y 기준 정렬했던 것이 유지된다.
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  pair<int, int> c[n];
  for(auto &x : c) cin >> x.first >> x.second;
  stable_sort(c, c+n, [&](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  stable_sort(c, c+n, [&](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  });
  for(auto x : c) cout << x.first << ' ' << x.second << '\n'; 
  return 0;
}