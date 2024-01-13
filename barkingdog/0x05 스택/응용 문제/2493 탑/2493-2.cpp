#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int h;
stack<pair<int, int>> S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    S.push({INT_MAX, 0}); // 더미 데이터를 넣어서 처리 깔끔하게 함.
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> h;
        while(S.top().X < h)
            S.pop();
        cout << S.top().Y << ' ';
        S.push({h,i});
    }
    return 0;
}