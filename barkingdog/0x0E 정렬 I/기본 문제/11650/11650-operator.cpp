/*
그냥 sort 를 이용할 경우 내부적으로 pair 끼리 < 연산을 진행하게 되는데,
pair 의 < 연산은 first 를 비교하고, 같을 경우 second 를 비교한다.
따라서, 그냥 stl 의 sort 를 돌려도 무방하다. 
https://stackoverflow.com/questions/23816797/how-does-stdsort-work-for-list-of-pairs
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
  sort(c, c+n);
  for(auto x : c) cout << x.first << ' ' << x.second << '\n'; 
  return 0;
}