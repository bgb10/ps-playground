/*
lower bound: 수를 넣었을 때 오름차순이 유지되는 가장 왼쪽 위치
upper bound: 수를 넣었을 때 오름차순이 유지되는 가장 오른쪽 위치
*/

#include <bits/stdc++.h>

using namespace std;

int A[500001];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    sort(A, A+n);
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        // 정렬되어 있을 때 이분탐색을 기반으로 하는 lower, upper bound 함수를 사용해 개수 측정 가능
        cout << upper_bound(A, A+n, k) - lower_bound(A, A+n, k) << ' ';
    }
    return 0;
}