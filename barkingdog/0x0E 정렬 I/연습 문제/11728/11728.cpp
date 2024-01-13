#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000001];
int b[1000001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> a[i];
  for(int i=0; i<m; i++)
    cin >> b[i];
  int p1 = 0;
  int p2 = 0;
  while(1) {
    if(p1 >= n) {
      while(p2 != m) {
        cout << b[p2++] << ' ';
      }
      break;
    }
    else if(p2 >= m) {
      while(p1 != n) {
        cout << a[p1++] << ' ';
      }
      break;
    }
    if(a[p1] < b[p2])
      cout << a[p1++] << ' ';
    else
      cout << b[p2++] << ' ';
  }
  return 0;
}