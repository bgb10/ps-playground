/*
Counting Sort(계수 정렬)

역인덱스를 이용해 등장하는 수의 개수를 세고, 이를 출력해서 정렬하는 기법.

수의 범위가 대략 1000만 이하일 때 사용하는게 좋다.(128MB 는 3000만 정도의 int 배열을 가질 수 있음)

시간복잡도: O(N+K) (N 은 수의 개수, K는 수의 범위)

수의 범위 K 가 작을 때는 Counting Sort 가 굉장히 효율적인 정렬 방법이 될 수 있다. 
*/

#include <bits/stdc++.h>
using namespace std;

int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int cnt[401]; // 수의 등장 횟수를 역인덱스 방식으로 저장
int n = 10;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<n; i++)
    cnt[arr[i]]++;
  for(int i=0; i<=400; i++) {
    if(cnt[i] == 0) continue;
    for(int j=0; j<cnt[i]; j++)
      cout << i << ' ';
  }
  return 0;
}