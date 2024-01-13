/*
증가 수열이 만들어질 수 있도록 스택을 두고, 수를 읽으면서 스택에 있는 원소를 빼면서 
증가 수열을 만든다. 그리고 스택에 수를 넣을 때는 증가 수열이 만들어진 후이므로, 최대값을 계산한다.

얼핏보면 맞는 풀이 같지만, 기존에 있는 숫자들이 필요한데 더 작은 값을 읽을 때
스택에서 지워버린 경우 최대값을 구할 수 없다. 

반례는 아래와 같다.
10
1 100 2 50 60 3 5 6 7 200

따라서 이 문제는 스택으로 풀 수 있는 문제가 아니다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[1004];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  stack<int> S;
  int mx = a[0];
  int psum = a[0];
  S.push(a[0]);
  for(int i=1; i<n; i++) {
    while(!S.empty() && S.top() >= a[i]) {
      psum -= S.top(); S.pop();
    }
    S.push(a[i]);
    psum += a[i];
    mx = max(mx, psum);
  }
  cout << mx;
  return 0;
}