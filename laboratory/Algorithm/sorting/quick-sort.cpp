/*
Quick Sort(퀵 정렬)

pivot 을 올바른 위치에 넣으면서 pivot 을 중심으로 왼쪽에는 pivot 보다 작은 원소, 오른쪽에는 큰 원소가 들어간다.
pivot 을 중심으로 왼쪽 부분, 오른쪽 부분으로 나눠 이를 재귀적으로 반복해서 정렬해나간다.

시간복잡도: 평균적으로 O(NlogN), 모두가 정렬되어 있는 최악의 경우 O(N^2)

Merge Sort 보다 빠르지만, 최악의 경우 O(N^2) 기 때문에 직접 정렬을 구현하는 경우에는 Merge Sort 를 사용하자.

in-place sort(추가적인 공간이 필요하지 않음) 
*/
#include <bits/stdc++.h>
using namespace std;

int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;

void printArray() {
  for(int i=0; i<n; i++)
    cout << arr[i] << ' ';
}

void quickSortOnlyOnePivot() {
  int pivot = arr[0];
  int l = 1;
  int r = n-1;
  while(1) {
    while(l <= r && arr[l] <= pivot) l++;
    while(l <= r && arr[r] > pivot) r--;
    if(l > r) break;
    swap(arr[l], arr[r]);
  }
  swap(arr[0], arr[r]);
}

void quickSort(int st, int en) {
  if(st >= en-1) return;
  int pivot = arr[st];
  int l = st + 1;
  int r = en - 1;
  while(1) {
    while(l <= r && arr[l] <= pivot) l++;
    while(l <= r && arr[r] > pivot) r--;
    if(l > r) break;
    swap(arr[l], arr[r]);
  }
  swap(arr[st], arr[r]);
  quickSort(st, r);
  quickSort(r+1, en);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  quickSort(0, n);
  printArray();
  return 0;
}