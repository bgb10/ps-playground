/*
입력 순서를 다르게 하고, 부호를 반전시켜 compare함수 작성 없이도 쉽게 풀 수 있게 한 센스있는 풀이.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int, string>> V;
  int kor;
  int eng;
  int math;
  string name;
  for(int i=0; i<n; i++) {
    cin >> name >> kor >> eng >> math;
    V.push_back({-kor, eng, -math, name});
  }
  sort(V.begin(), V.end());
  for(auto& e : V) {
    cout << get<3>(e) << '\n';
  }
  return 0;
}