#include <bits/stdc++.h>
using namespace std;

bool arr[2000004] = {}; //2MB ~ 3MB, O(N)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int t;
    cin >> n;
    int x;

    for(int i=0; i<n; i++) {
        cin >> t;
        arr[t] = true;
    } 

    cin >> x;

    int cnt = 0;
    int mid = (x - 1) / 2;
    for(int i=mid; i>=1; i--) {
        if(arr[i] && arr[x - i]) cnt++;
    }

    cout << cnt;

    return 0;
}