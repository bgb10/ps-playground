#include <bits/stdc++.h>
using namespace std;

int n, s;

int arr[25];
int cnt = 0;

void solve(int k, int sum) {
  if(k >= n) {
    if(sum == s) cnt++;
    return;
  }

  solve(k+1, sum + arr[k]);
  solve(k+1, sum);
}

int main() {
  cin >> n >> s;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  solve(0, 0);

  if(s == 0) cnt--;
  cout << cnt;
  return 0;
}