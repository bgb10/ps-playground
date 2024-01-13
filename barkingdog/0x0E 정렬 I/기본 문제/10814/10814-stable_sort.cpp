#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  pair<int, string> x[n];
  for(auto &s: x) cin >> s.first >> s.second;
  // [&] 는 cpp 의 람다 표현식 연산자 중 하나로, 현재의 변수들을 모두 reference 로 취급한다는 뜻이다.
  // value 로 취급하는 [=] 을 사용할 경우 수행 시간이 68ms 에서 76ms 로 증가하였다. 
  stable_sort(x, x+n, [&](pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
  });
  for(auto p : x) cout << p.first << ' ' << p.second << '\n';
  return 0;
}