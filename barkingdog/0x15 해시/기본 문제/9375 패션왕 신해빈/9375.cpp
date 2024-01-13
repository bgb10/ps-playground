/*
hash map 과 약간의 경우의 수를 따지면 풀 수 있는 문제.

여러 종류의 옷이 주어지는데, 사실 하나의 종류의 여러 의상들의 이름은 중요하지 않고, 의상의 개수만 중요하다.
경우의 수만을 따지면 되기 때문이다.
따라서 의상의 종류에 따른 의상의 개수를 저장할 수 있어야 하는데, 배열에 이를 저장하면 탐색 비용이 생긴다.
따라서 key 가 string 이고 value 가 int 인 hash map 을 사용하면 된다.
입력을 잘 저장했다면, 만약 첫번째 예시에서처럼 headgear 2개, eyewear 1개가 있을 때
headgear 를 안입는 경우까지 포함한 3 경우, eyewear 를 안입는 경우까지 포함한 2 경우를 곱하고
모두 안입는 경우를 제외해야 하므로 1경우를 빼면 된다.
이를 일반화해서 모든 입력에 적용하면 된다.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    unordered_map<string, int> UM;
    for(int i=0; i<n; i++) {
      string name, kind;
      cin >> name >> kind;
      if(UM.find(kind) != UM.end()) {
        UM[kind]++;
      }
      else {
        UM[kind] = 1;
      }
    }
    int cnt = 1;
    for(auto& i : UM) {
      cnt *= (i.second + 1);
    }
    cout << cnt - 1 << '\n';
  }
  return 0;
}