#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int ans[10];

void func(int cnt) { 
    if(cnt == m) {
        for(int i=0; i<m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        ans[cnt] = arr[i];
        func(cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    func(0);
    return 0;
}