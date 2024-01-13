#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> V1;
    vector<int> V2;
    int e;
    for(int i=0; i<n; i++) {
      cin >> e;
      V1.push_back(e);
    }
    for(int i=0; i<m; i++) {
      cin >> e;
      V2.push_back(e);
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    int cnt = 0;
    for(int i : V1) {
      cnt += upper_bound(V2.begin(), V2.end(), i-1) - V2.begin();
    }
    cout << cnt << '\n';
  }
  
  return 0;
}