#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<string> V;
  // iterator 를 이용한 substring 추출
  // for(auto it = s.begin(); it != s.end(); it++) {
  //   V.push_back(string(it, s.end()));
  // }
  // substring 함수를 이용한 substring 추출
  // substr(시작 위치, 사이즈) : 사이즈를 제공하지 않을 경우 문자열 끝까지
  int strl = s.length();
  for(int i=0; i<strl; i++) {
    V.push_back(s.substr(i));
  }
  sort(V.begin(), V.end());
  for(auto& s : V) {
    cout << s << '\n';
  }
  return 0;
}