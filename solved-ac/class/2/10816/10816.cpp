#include <bits/stdc++.h>
using namespace std;

int cnt[20000003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    int t;
    for(int i=0; i<n; i++) {
        cin >> t;
        cnt[t + 10000000]++;
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> t;
        cout << cnt[t + 10000000] << ' ';
    }
    return 0;
}