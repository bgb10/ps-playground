/*
해시 맵의 정의와 성질을 아는지 묻는 간단한 문제.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> UM;
  string s, p;
  for(int i=0; i<n; i++) {
    cin >> s >> p;
    UM[s] = p;
  }
  for(int i=0; i<m; i++) {
    cin >> s;
    cout << UM[s] << '\n';
  }
  return 0;
}