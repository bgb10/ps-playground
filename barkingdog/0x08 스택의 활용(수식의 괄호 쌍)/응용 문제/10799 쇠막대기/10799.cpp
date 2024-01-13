#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> m;
    char before = 'i';
    int ans = 0;
    for(char c : s) {
        if(before == '(' && c == ')') {
            ans += m.size() - 1;
            m.pop();
        } else if(c == ')') {
            m.pop();
            ans += 1;
        } else {
            m.push(c);
        }
        before = c;
    }

    cout << ans;

    return 0;
}