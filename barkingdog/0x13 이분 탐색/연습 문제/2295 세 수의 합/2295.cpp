/*
얼핏 보면 O(N^4)의 풀이를
이분 탐색을 이용해 O(N^2lgN)에 풀 수 있는 문제

a + b + c = d 를 a + b = d - c 로 치환하고, a+b를 미리 구해놓는데 O(N^2), d-c loop를 도는데 O(N^2), 그리고 d-c에 대해 a+b 가 존재하는지 찾는데에 O(lg(N^2)) 가 들어
총 시간복잡도는 O(N^2lgN) 이 된다.

# 이렇게 두 개의 값을 묶어서 미리 구해놓고 값을 이분탐색으로 검색해서 시간복잡도를 낮추는 아이디어는 굉장히 많이 나오는 문제 유형이다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  sort(a, a+n);
  vector<int> sum;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      sum.push_back(a[i] + a[j]);
    }
  }
  sort(sum.begin(), sum.end());
  for(int i=n-1; i>0; i--) {
    for(int j=0; j<i; j++) {
      if(binary_search(sum.begin(), sum.end(), a[i]-a[j])) {
        cout << a[i];
        return 0;
      }
    }
  }
  return 0;
}