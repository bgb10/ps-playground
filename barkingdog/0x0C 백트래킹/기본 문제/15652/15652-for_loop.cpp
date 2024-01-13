#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int cur, int k) {
    arr[k] = cur;
    k++;
    if(k == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = cur; i <= n; i++) func(i, k);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) func(i, 0);
    return 0;
}