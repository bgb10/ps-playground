#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        stack<char> S;
        bool vps = true;
        for(char c : s) {
            if(!S.empty() && c == ')') {
                if(S.top() == '(')
                    S.pop();
                else {
                    vps = false;
                    break;
                }
            }
            else {
                S.push(c);
            }
        }
        if(!S.empty())
            vps = false;
            
        if(vps)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}