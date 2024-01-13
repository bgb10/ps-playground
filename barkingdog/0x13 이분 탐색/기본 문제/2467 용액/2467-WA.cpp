/*
이진 탐색에서 어느 논리가 틀렸는지 잘 모르겠다. 
나중에 한번 다시 보고 반례를 찾아보자.
*/

#include <bits/stdc++.h>
using namespace std;

int a[100002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ansmn = abs(a[0] + a[1]);
    int ans1 = 0, ans2 = 1;
    for(int i=0; i<n-1; i++) {
        int mn = abs(a[i] + a[i+1]);
        int st = i+1;
        int en = n-1;
        while(st < en) {
            int mid = (st + en + 1) / 2;
            if(abs(a[i] + a[mid]) < mn) {
                st = mid;
                mn = abs(a[i] + a[mid]);
            }
            else {
                en = mid - 1;
            }
        }
        if(mn < ansmn) {
            ansmn = mn;
            ans1 = i;
            ans2 = st;
        }
    }
    cout << a[ans1] << ' ' << a[ans2];
	return 0;
}