/*
Bubble Sort (거품 정렬)

바로 앞 원소와 비교해서 최대(최소) 값을 뒤로 하나씩 밀어서 정렬한다.

시간복잡도: O(N^2)

원소의 이동이 거품이 수면에 올라오는 것처럼 느껴진다고 해서 '거품 정렬'로 이름지어짐.
*/

#include <bits/stdc++.h>
using namespace std;

int arr[5] = {-2, 2, 4, 6, 13};
int n = 5;

void printArray() {
  for(int i=0; i<n; i++) {
    cout << arr[i] << ' ';
  }
}

void ascending() {
  for(int i =0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
  }
}

void descending() {
  for(int i =0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(arr[j] < arr[j+1]) swap(arr[j], arr[j+1]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ascending();
  printArray();

  cout << '\n';
  descending();
  printArray();
  return 0;
}