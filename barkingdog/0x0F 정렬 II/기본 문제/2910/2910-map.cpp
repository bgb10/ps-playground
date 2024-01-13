#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> M;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  vector<int> V(n);
  for(auto& i : V) {
    cin >> i;
    auto res = M.find(i);
    if(res == M.end()) 
      M.insert({i, 1});
    else
      res->second++;
  }
  stable_sort(V.begin(), V.end(), [=](int a, int b) {
    return M.find(a)->second > M.find(b)->second;
  });
  for(auto& i : V) {
    for(int j=0; j< M.find(i)->second; j++) cout << i << '\n';
    M.find(i)->second = 0;
  }
  return 0;
}