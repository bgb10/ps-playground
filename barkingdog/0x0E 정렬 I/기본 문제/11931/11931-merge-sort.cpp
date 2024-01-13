/*
Merge Sort 를 이용한 풀이 O(NlgN)
*/

#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001];
int n;

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
  mergeSort(0, n);
  for(int i=0; i<n; i++)
    cout << arr[i] << '\n';
  return 0;
}