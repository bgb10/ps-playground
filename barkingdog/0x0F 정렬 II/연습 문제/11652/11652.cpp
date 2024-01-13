#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll arr[100001];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  int mxidx = 0;
  int mxcnt = 1;
  int cnt = 1;
  ll bf = arr[0];
  for (int i = 1; i < n; i++) {
    if (bf == arr[i])
      cnt++;
    else {
      bf = arr[i];
      if (mxcnt < cnt) {
        mxidx = i - 1;
        mxcnt = cnt;
      }
      cnt = 1;
    }
  }
  if (mxcnt < cnt) {
    mxidx = n - 1;
  }
  cout << arr[mxidx];
  return 0;
}