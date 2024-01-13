#include <bits/stdc++.h>
using namespace std;

bool solve(tuple<string, int, int, int>& a, tuple<string, int, int, int>& b) {
  if(get<1>(a) != get<1>(b)) {
    return get<1>(a) > get<1>(b);
  }

  if(get<2>(a) != get<2>(b)) {
    return get<2>(a) < get<2>(b);
  }

  if(get<3>(a) != get<3>(b)) {
    return get<3>(a) > get<3>(b);
  }

  return get<0>(a) < get<0>(b);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<string, int, int, int>> V(n);
  for(auto& e : V) {
    cin >> get<0>(e) >> get<1>(e) >> get<2>(e) >> get<3>(e);
  }
  sort(V.begin(), V.end(), solve);
  for(auto& e : V) {
    cout << get<0>(e) << '\n';
  }
  return 0;
}