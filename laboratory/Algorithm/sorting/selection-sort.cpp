/* 
  Selection Sort (선택 정렬)

  순서가 정해지지 않은 부분의 최대(최소)값을 구해서 순서가 정해진 현재 위치의 값을 구한다.

  시간복잡도: 0(N^2)

  i 는 부분의 최대값을 넣을 장소, j 는 순서가 정해지지 않은 부분을 탐색할 인덱스
  mxidx 는 순서가 정해지지 않은 부분의 최대 값의 인덱스를 의미한다.
*/

#include <bits/stdc++.h>
using namespace std;

int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;

void printArray() {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
}

void ascending() {
  for (int i = n - 1; i > 0; i--) {
    int mxidx = 0;
    for (int j = 1; j <= i; j++) {
      if (arr[mxidx] < arr[j])
        mxidx = j;
    }
    swap(arr[mxidx], arr[i]);
  }
}

void descending() {
  for (int i = 0; i < n - 1; i++) {
    int mxidx = n - 1;
    for (int j = n - 2; j >= i; j--) {
      if (arr[mxidx] < arr[j]) {
        mxidx = j;
      }
    }
    swap(arr[mxidx], arr[i]);
  }
}

void descending2() {
  for(int i=0; i<n-1; i++) {
    int mxidx = n-1;
    for(int j=i; j<n-1; j++) {
      if(arr[mxidx] < arr[j]) {
        mxidx = j;
      }
    }
    swap(arr[mxidx], arr[i]);
  }
}

void ascendingByMaxElement() {
  for(int i = n-1; i>0; i--) {
    swap(arr[i], *max_element(arr, arr+i+1)); // max_element 이기 때문에 i+1 이다.
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << '\n';
  ascending();
  printArray();

  cout << '\n';
  descending();
  printArray();

  cout << '\n';
  ascending();
  descending2();
  printArray();

  cout << '\n';
  ascendingByMaxElement();
  printArray();

  return 0;
}