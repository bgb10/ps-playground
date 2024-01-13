/*
Insertion Sort(삽입 정렬)

2번째 원소부터 시작하여 그 앞의 원소들과 비교하여 삽입할 위치를 지정한 후,
원소를 사이에 삽입하는 알고리즘

시간복잡도: O(N^2) (이미 모든 원소가 정렬된 경우인 경우 O(N) 이라서 다른 정렬 알고리즘의 일부로 사용)

Selection Sort 는 정렬되지 않은 부분에서 필요한 요소를 찾기 위해 부분을 모두 탐색하지만,
Insertion Sort 는 자신이 삽입될 위치만 찾으면 되기 때문에 전체 탐색을 하지 않아 훨씬 효율적이다.
*/

#include <bits/stdc++.h>
using namespace std;

list<int> L;
int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;

void printArray() {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
}

void printLinkedList() {
  for(int i : L)
    cout << i << ' ';
}

void ascendingByLinkedList() {
  L.push_back(arr[0]);
  
  for(int i = 1; i < n; i++) {
    for(auto it = L.begin(); it != L.end(); it++) {
      // 여기서 n 번을 다 안돌 수 있기 때문에 선택 정렬보다 효율적
      if(arr[i] < *it) {
        L.insert(it, arr[i]);
        break;
      }
      if(it == --L.end()) {
        L.push_back(arr[i]); 
        break;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ascendingByLinkedList();
  printLinkedList();  

  return 0;
}