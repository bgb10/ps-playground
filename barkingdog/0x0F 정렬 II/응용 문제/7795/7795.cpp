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
    int aidx = 0;
    int bidx = 0;
    int cnt = 0;
    while(aidx < n) {
      if(bidx == m) {
        cnt += bidx;
        aidx++;
        continue;
      }
      if(V1[aidx] > V2[bidx]) {
        bidx++;
      }
      else {
        cnt += bidx;
        aidx++;
      }
    } 
    cout << cnt << '\n';
  }
  
  return 0;
}