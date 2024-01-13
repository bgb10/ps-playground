/*
구간합을 구하는 투포인터 문제.

[st, en) 에 대해
S = A[st] + ... + A[en-1] 라고 하면
i) S == M: cnt++, en == n 이 아니라면 en++
ii) S > M: st++
iii) S < M: en++, en == n 이 아니라면 en++

시간복잡도는 O(N) 이다.

# 구간합을 구하는 문제는 대부분 투포인터, 이분탐색으로 해결할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int st = 0, en = 0;
    int psum = 0;
    int cnt = 0;
    while(1) {
        if(psum == m) {
            cnt++;
            if(en == n) break;
            psum += a[en];
            en++;
        }
        else if(psum > m) {
            psum -= a[st];
            st++;
        }
        else {
            if(en == n) break;
            psum += a[en];
            en++;
        }
    }
    cout << cnt;
    return 0;
}