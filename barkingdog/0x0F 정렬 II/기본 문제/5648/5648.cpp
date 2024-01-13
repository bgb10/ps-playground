// 문자열을 사용한 풀이

#include <bits/stdc++.h>
using namespace std;

string s[1000001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string t;
  for(int i=0; i<n; i++) {
    cin >> t;
    reverse(t.begin(), t.end());
    for(auto it = t.begin(); it != t.end(); it++) {
      if(*it != '0') {
        s[i] = string(it, t.end());
        break;
      }
    }
  }
  sort(s, s+n, [&](string a, string b) {
    if(a.length() != b.length()) {return a.length() < b.length();}
    return a < b;
  });
  for(int i=0; i<n; i++)
    cout << s[i] << '\n';
  return 0;
}