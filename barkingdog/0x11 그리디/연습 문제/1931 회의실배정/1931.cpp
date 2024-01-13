/*
최대한 빨리 끝나는 일정을 택해서 개수를 세면 되는 그리디 풀이.

Brute force: O(2^N)
DP: O(N^2)
Greedy: O(N)
*/

#include <bits/stdc++.h>
using namespace std;
#define S second
#define E first

pair<int, int> arr[100001]; // end, start

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr[i].S >> arr[i].E;
  }
  sort(arr, arr+n);
  int before = 0;
  int cnt = 0;
  for(int i=0; i<n; i++) {
    if(before > arr[i].S) continue;
    cnt++;
    before = arr[i].E;
  }
  cout << cnt;
  
  return 0;
}