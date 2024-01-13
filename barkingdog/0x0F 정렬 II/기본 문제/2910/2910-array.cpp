#include <bits/stdc++.h>
using namespace std;

int n, c;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  vector<pair<int, int>> V(n); // (수, 수의 개수)
  // n 이 1000 이니까 map 으로 푼 nlogn 이 아닌 n^2 도 상관없다.
  for(int i=0; i<n; i++) {
    int k;
    cin >> k;
    bool isexist = false;
    for(auto& e : V) {
      if(e.first == k) {
        isexist = true;
        e.second++;
        break;
      }
    }
    if(!isexist) {
      V.push_back({k, 1});
    }
  }
  stable_sort(V.begin(), V.end(), [&](pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  });
  for(auto& e : V) {
    for(int i=0; i<e.second; i++) {
      cout << e.first << '\n';
    }
  }
  return 0;
}