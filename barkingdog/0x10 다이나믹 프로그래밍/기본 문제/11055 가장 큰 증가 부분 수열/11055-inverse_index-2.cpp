/*
mxsum[p] : 현재 수가 p 일때의 최대 구간 연속합

mxsum[p] = max(mxsum[k] 들) + a[i] (k 는 p 보다 작은 수들)
현재 수가 p 일때의 최대 구간 연속합은 현재 수 p 보다 작은 k에 대한 모든 최대 구간 연속합 중 최대값과 현재 수를 더한 것과 같다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[1004];
int mxsum[1004];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    mxsum[a[1]] = a[1];
    for(int i=2; i<=n; i++) {
        int mx = 0;
        for(int j=1; j<a[i]; j++) {
            mx = max(mx, mxsum[j]);
        }
        mxsum[a[i]] = mx + a[i];
    }
    cout << *max_element(mxsum, mxsum+1001);
	return 0;
}