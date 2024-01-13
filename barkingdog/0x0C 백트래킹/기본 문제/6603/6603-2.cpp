#include <bits/stdc++.h>
using namespace std;

bool isused[20];
int arr[20];
int ans[20];
int k;

void func(int p, int st) {
    if(p == 6) {
        for(int i=0; i<6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=st; i<k; i++) {
        if(isused[i]) continue;
        isused[i] = 1;
        ans[p] = arr[i];
        func(p+1, i+1);
        isused[i] = 0;
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> k;
    while(k != 0) {
        for(int i=0; i<k; i++)
            cin >> arr[i];
        func(0, 0);
        cout << '\n';
        cin >> k;
    }

    return 0;
}