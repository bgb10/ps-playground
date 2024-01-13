#include <bits/stdc++.h>
using namespace std;


int n;

int ans[20];

void solve(int k) {
    if(k == n) {
        for(int i=0; i<n; i++) {
            cout << ans[i];
        }
        cout << '\n';
        return;
    }
    ans[k] = 0;
    solve(k+1);
    ans[k] = 1;
    solve(k+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 재귀를 이용해서 2^n 의 경우의 수를 구합니다.
    cin >> n;
    solve(0);
    return 0;
}