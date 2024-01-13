#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    char bf;
    stack<char> S;
    int cnt = 0;
    for(char c : s) {
        if(c == '(')
            S.push(c);
        else if(bf == '(' && c == ')') {
            S.pop();
            cnt += S.size();
        }
        else if(c == ')') {
            cnt++;
            S.pop();
        }
        bf = c;
    }
    cout << cnt;
    return 0;
}