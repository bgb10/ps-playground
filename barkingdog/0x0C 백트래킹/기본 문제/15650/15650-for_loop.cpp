#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k, int num) {
    arr[k] = num;
    k++;
    if(k == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num + 1; i<=n; i++) func(k, i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) func(0, i);
    return 0;
}