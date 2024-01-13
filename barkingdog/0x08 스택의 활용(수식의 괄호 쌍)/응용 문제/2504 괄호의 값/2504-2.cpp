#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> S;
    int ans = 0;
    int mul = 1;
    char bf = 0;
    for(char c : s) {
        if(c == '(') {
            S.push('(');
            mul *= 2;
        }
        else if(c == '[') {
            S.push('[');
            mul *= 3;
        }
        else if(bf == '(' && c == ')') {
            S.pop();
            mul /= 2;
            ans += 2 * mul;
        }
        else if(bf == '[' && c == ']') {
            S.pop();
            mul /= 3;
            ans += 3 * mul;
        }
        else if(!S.empty()) {
            if(S.top() == '(' && c == ')') {
                S.pop();
                mul /= 2;
            }
            else if(S.top() == '[' && c == ']') {
                S.pop();
                mul /= 3;
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else {
            cout << 0;
            return 0;
        }

        bf = c;
    }
    if(!S.empty())
        ans = 0;

    cout << ans;
    return 0;
}