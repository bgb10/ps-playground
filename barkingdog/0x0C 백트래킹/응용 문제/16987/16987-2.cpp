#include <bits/stdc++.h>
using namespace std;

int n;
int s[10];
int w[10];
int mx = 0;
int cnt = 0;

void solve(int e) {
    if(e == n || cnt == n-1) { // 마지막에 계란이 하나 남았을 경우, max 를 연산하기 위함.
        mx = max(mx, cnt);
        return;
    }
    if(s[e] <= 0) {
        solve(e+1);
        return;
    }
    for(int i=0; i<n; i++) {
        if(i == e) continue;
        if(s[i] <= 0) continue;
        s[e] -= w[i];
        s[i] -= w[e];
        if(s[e] <= 0) cnt++;
        if(s[i] <= 0) cnt++;
        solve(e+1);
        if(s[e] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[e] += w[i];
        s[i] += w[e];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i] >> w[i];
    solve(0);
    cout << mx;
    return 0;
}