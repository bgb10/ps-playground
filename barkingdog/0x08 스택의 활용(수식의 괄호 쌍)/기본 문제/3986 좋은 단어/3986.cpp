#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int cnt = 0;
    while(t--) {
        string s;
        cin >> s;
        stack<char> S;
        for(char c : s) {
            if(!S.empty() && S.top() == c)
                S.pop();
            else
                S.push(c);
        }
        if(S.empty())
            cnt++;
    }
    cout << cnt;
    return 0;
}