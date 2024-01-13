/*
가장 긴 증가하는 부분 수열 2와 같으므로 풀이는 생략한다.
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define SIZE 1000005

int a[SIZE];
int LIS[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    fill(LIS, LIS+SIZE, INT_MAX);
    for(int i=0; i<n; i++) {
        int idx = lower_bound(LIS, LIS+SIZE, a[i]) - LIS;
        LIS[idx] = a[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(LIS[i] != INT_MAX) {
            ans = i;
        }
    }
    cout << ans + 1;
    return 0;
}