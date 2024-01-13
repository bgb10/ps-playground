/*
Radix Sort(기수 정렬)

자리수를 통해 수를 비교해서 정렬(1의 자리수 정렬 -> 10의 자리수 정렬 -> ...)

시간복잡도: O(N*K) 이때 K 는 최대 자리수

코딩테스트에서 구현할 일이 전혀 없다.
stl 이 제공되는 경우 sort를 사용하면 되고, 안되더라도 merge sort 나 quick sort
를 구현할 것이기 때문.
*/

#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {3, 0, 1, 44, 61, 2364, 99, 9, 8765, 1};
int d = 3;
int p10[3];
vector<int> l[10];

int getDigit(int num, int a) { return (num / p10[a]) % 10; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  p10[0] = 1;
  for (int i = 1; i <= d; i++)
    p10[i] = p10[i - 1] * 10;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) {
      int digit = getDigit(arr[j], i);
      l[digit].push_back(arr[j]);
    }
    int aidx = 0;
    for (auto v : l) {
      for (auto e : v) {
        arr[aidx++] = e;
      }
    }
    for (int j = 0; j < n; j++)
      l[j].clear();
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}