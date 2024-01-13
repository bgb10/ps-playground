// stoll 함수를 사용한 풀이

#include <bits/stdc++.h>
using namespace std;

long long arr[1000001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string t;
  for(int i=0; i<n; i++) {
    cin >> t;
    reverse(t.begin(), t.end());
    arr[i] = stoll(t);
  }
  sort(arr, arr+n);
  for(int i=0; i<n; i++)
    cout << arr[i] << '\n';
  return 0;
}