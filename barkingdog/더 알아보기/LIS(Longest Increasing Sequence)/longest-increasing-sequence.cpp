/*
LIS를 O(NlgN) 로 구하는 방법

길이가 idx + 1 인 LIS의 마지막 값을 저장하는 배열을 이용한다.

수열을 순차적으로 확인한다고 했을 때 수열에 등장하는 수들이 이전의 LIS를 활용하기 위해서는,
'자신의 수보다 작은지' 가 가장 중요하다.
따라서, '자신의 수보다 작은지'를 빠르게 확인할 수 있는 방법이 필요하다.
이는 이분탐색을 이용해 구현할 수 있다.
배열의 인덱스는 LIS의 길이를 의미하고, 배열의 값은 이전에 구한 LIS의 마지막 값이 들어간다.
이분 탐색을 이용해 이전에 구한 LIS의 마지막 값 중 현재 원소보다 작고, 인덱스가 가장 큰 원소를 찾아
해당 원소 다음에 넣어주면 된다.
*/
#include <bits/stdc++.h>
#include <algorithm>
#include <set>
using namespace std;
#define X first
#define Y second
#define SIZE 1000005

int a[SIZE];
int last[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    fill(last, last+SIZE, 0x7f7f7f7f);
    for(int i=0; i<n; i++) {
        int idx = lower_bound(last, last+SIZE, a[i]) - last;
        last[idx] = a[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(last[i] != 0x7f7f7f7f) {
            ans = i;
        }
    }
    cout << ans + 1;
    return 0;
}