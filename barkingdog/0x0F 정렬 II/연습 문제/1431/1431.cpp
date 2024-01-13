#include <bits/stdc++.h>
#include <queue>
using namespace std;

string arr[51];

bool solve(string &a, string &b) {
  // 길이 비교
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }

  // 자리수 합 비교
  int acnt = 0;
  int bcnt = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] - '0' < 10)
      acnt += a[i] - '0';
    if (b[i] - '0' < 10)
      bcnt += b[i] - '0';
  }
  if (acnt != bcnt) {
    return acnt < bcnt;
  }

  // 사전순 비교
  return a < b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n, solve);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << '\n';
  }
  return 0;
}