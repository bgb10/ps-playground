#include <bits/stdc++.h>
using namespace std;

int a[1000004];
int b[1000004];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k;
    for(int i=0; i<n; i++) {
        cin >> k;
        a[k]++;
    }
    for(int i=0; i<n; i++) {
        cin >> k;
        b[k]++;
    }
    int cnt = 0;
    for(int i=0; i<=1000000; i++) {
        if(a[i] - b[i] > 0)
            cnt += a[i] - b[i];
    }
    cout << cnt;
    return 0;
}