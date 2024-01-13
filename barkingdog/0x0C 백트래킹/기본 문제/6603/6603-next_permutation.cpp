#include <bits/stdc++.h>
using namespace std;

int t;
int arr[20];

void func() {
    int ans[20];
    fill(ans, ans+6, 0);
    fill(ans+6, ans+t, 1);
    do {
        for(int i=0; i<t; i++) {
            if(ans[i] == 0)
                cout << arr[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(ans, ans+t));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t != 0) {
        for(int i=0; i<t; i++)
            cin >> arr[i];
        func();
        cout << '\n';
        cin >> t;
    }
    return 0;
}