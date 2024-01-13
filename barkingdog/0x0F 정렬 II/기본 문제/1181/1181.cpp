#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; i++) {
    cin >> s[i];
  }
  sort(s.begin(), s.end(), [&](string a, string b) {
    if(a.length() != b.length()) return a.length() < b.length();
    return a < b;
  });
  s.erase(unique(s.begin(), s.end()), s.end());
  for(auto& i : s) {
    cout << i << '\n';
  }
  return 0;
}