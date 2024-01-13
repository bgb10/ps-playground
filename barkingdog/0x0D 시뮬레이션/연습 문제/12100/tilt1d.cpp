#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[8] = {0, 2, 0, 2, 8, 8, 0, 16};
  int tilted[8] = {};
  int idx = 0; // 현재 블록을 놓을 수 있는 위치를 표시
  for(int i=0; i<8; i++) {
    if(arr[i] == 0) continue;
    if(tilted[idx] == 0)
      tilted[idx] = arr[i];
    else if(tilted[idx] == arr[i])
      tilted[idx++] *= 2;
    else
      tilted[++idx] = arr[i];
  }

  for(int i=0; i<8; i++)
    cout << tilted[i] << ' ';
  return 0;
}