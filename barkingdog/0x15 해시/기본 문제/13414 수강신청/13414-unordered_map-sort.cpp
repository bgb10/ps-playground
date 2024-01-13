/*
unordered_map 과 정렬로 해결한 문제

배열만을 사용할 경우 O(N^2) 이 필요하다. 따라서, 적절한 알고리즘이나 자료구조를 도입해야 하는데,
'가장 마지막에 넣은 값으로 덮어씌우는' 구조는 해시 맵 자료구조에서 볼 수 있다.
따라서, 수강신청이 들어올 때마다 해시 맵에 넣어주고,
해시 맵에 있는 요소를 배열에 그대로 넣어준다.
이후 배열을 수강신청 순서(int) 기준으로 정렬한 후 출력하면 된다. 이때 compare 함수 정의가 필요하다.
이를 통해 시간복잡도를 O(N) 으로 줄일 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> UM;
string order[500004];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int K, L;
  cin >> K >> L;
  string subject;
  for(int i=0; i<L; i++) {
    cin >> subject;
    UM[subject] = i;
  }
  vector<pair<string, int>> V(UM.begin(), UM.end());
  sort(V.begin(), V.end(), [&](auto& a, auto& b){return a.second < b.second;});
  int s = min(K, (int)V.size());
  for(int i=0; i<s; i++) {
    cout << V[i].first << '\n';
  }
  return 0;
}