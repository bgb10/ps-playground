/*
투 포인터를 이용한 풀이.

# 이분 탐색으로도 풀 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[100002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int st = 0, en = 0;
    int mn = INT_MAX;
    while(en < n) {
        if(a[en] - a[st] < m) {
            en++;
        }
        else {
            mn = min(mn, a[en] - a[st]);
            st++;
        }
    }
    cout << mn;
	return 0;
}