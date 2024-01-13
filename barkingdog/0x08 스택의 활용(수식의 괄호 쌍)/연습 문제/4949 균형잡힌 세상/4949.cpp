#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);
    while(s != ".") {
        stack<char> S;
        bool balanced = true;
        for(char c : s) {
            if(c == '(' || c == '[')
                S.push(c);
            else if(c == ')') {
                if(!S.empty() && S.top() == '(')
                    S.pop();
                else {
                    balanced = false;
                    break;
                }
            }
            else if(c == ']') {
                if(!S.empty() && S.top() == '[')
                    S.pop();
                else {
                    balanced = false;
                    break;
                }
            }
            else
                continue;
        }
        if(!S.empty()) balanced = false;

        if(balanced) cout << "yes" << '\n';
        else cout << "no" << '\n';

        getline(cin, s);
    }

    return 0;
}