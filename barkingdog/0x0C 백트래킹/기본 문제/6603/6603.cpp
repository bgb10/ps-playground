#include <bits/stdc++.h>
using namespace std;

int arr[20];
int res[20];
int k;

void func(int cur, int st) {
    res[cur] = arr[st];
    cur++;
    if(cur == 6) {
        for(int i=0; i<6; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=st+1; i<=k-6+cur; i++) {
        func(cur, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    while(k != 0) {
        for(int i=0; i<k; i++)
            cin >> arr[i];
        for(int i=0; i<=k-6; i++)
            func(0, i);
        cout << '\n';
        cin >> k;
    }
    return 0;
}