#include <bits/stdc++.h>
using namespace std;

int arr[1000003];
int ans[1000003];
stack<int> S;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=n-1; i>=0; i--)
        cin >> arr[i];
    for(int i=0; i<n; i++) {
        while(!S.empty() && S.top() <= arr[i])
            S.pop();
        if(S.empty()) 
            ans[i] = -1;
        else
            ans[i] = S.top();
        S.push(arr[i]);
    }
    for(int i=n-1; i>=0; i--)
        cout << ans[i] << ' ';
    return 0;
}