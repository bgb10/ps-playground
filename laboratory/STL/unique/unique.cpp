#include <bits/stdc++.h>
using namespace std;

vector<int> v = { 10, 30, 20, 20, 40, 40, 40, 50, 10, 20, 30};

void printVector() {
  for(auto& i : v) {
    cout << i << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << "원본 배열" << '\n';
  printVector();

  cout << '\n';

  cout << "unique 함수를 사용한 중복 제거" << '\n';
  cout << "중복은 제거되었지만 뒤에 중복되지 않은 다른 이상한 값으로 대체되어 들어감. " << '\n';
  auto it = unique(v.begin(), v.end());
  printVector();

  cout << '\n';

  cout << "resize 함수를 사용한 이상한 값 제거" << '\n';
  v.resize(distance(v.begin(), it));
  printVector();

  cout << '\n';

  cout << "정렬 후 중복된 값 제거하는 과정" << '\n';
  v = { 10, 30, 20, 20, 40, 40, 40, 50, 10, 20, 30};
  sort(v.begin(), v.end()); // 정렬
  v.erase(unique(v.begin(), v.end()), v.end()); // unique 수행 후 반환된 iterator 부터 vector 의 끝까지 삭제
  printVector();

  return 0;
}