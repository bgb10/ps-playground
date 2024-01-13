/*
Quick Sort 를 이용한 풀이 O(NlgN) 최악의 경우 O(N^2)

이 문제는 최악의 경우에 대해 O(N^2) 일 경우 터지기 때문에 N이 커질 경우는 O(NlgN)인 Merge Sort 로 해결해야 한다.
직접 소트 함수를 작성할 필요 없이, stl 의 sort 를 사용할 수도 있다.
이 경우, stl sort 가 quick sort 라고 생각하는 사람이 많지만, 사실은 quick sort 의 장점을 보완하기 위해
여러 정렬 방법을 섞은 intro sort 가 사용되었다. 
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001];
int n;

void quickSort(int st, int en) {
  if(en - st <= 1) return;
  int pivot = arr[st];
  int l = st+1;
  int r = en-1;
  while(1) {
    while(l <= r && arr[l] >= pivot) l++;
    while(1 <= r && arr[r] < pivot) r--;
    if(l > r) break;
    swap(arr[l], arr[r]);
  }
  swap(arr[st], arr[r]);
  quickSort(st, r);
  quickSort(r+1, en);
}

void merge(int st, int en) {
  int mid = (st + en) / 2;
  int l = st;
  int r = mid;
  for(int i = st; i<en; i++) {
    if(l >= mid) {
      tmp[i] = arr[r++];
    }
    else if(r >= en) {
      tmp[i] = arr[l++];
    }
    else if(arr[l] >= arr[r]) {
      tmp[i] = arr[l++];
    }
    else {
      tmp[i] = arr[r++];
    }
  }
  for(int i = st; i<en; i++)
    arr[i] = tmp[i];
}

void mergeSort(int st, int en) {
  if(en - st == 1) return;
  int mid = (st + en) / 2;
  mergeSort(st, mid);
  mergeSort(mid, en);
  merge(st, en);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  if(n < 5000) 
    quickSort(0, n);
  else
    mergeSort(0, n);
  for(int i=0; i<n; i++)
    cout << arr[i] << '\n';
  return 0;
}