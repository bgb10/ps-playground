#include <bits/stdc++.h>
using namespace std;

int ans[10];
int n, m;

void func(int cur, int k) {
    if(k == m) {
        for(int i=0; i<m; i++) cout << ans[i] << ' ';
        cout < < '\n';
        return;
    } 
    for(int i=cur; i<=n; i++) {
        ans[k] = i;
        func(cur, k + 1);
    }    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(1, 0);
    return 0;
}