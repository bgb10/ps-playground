#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        string s;
        cin >> s;
        if(s == "0") break;
        string rs = s;
        reverse(rs.begin(), rs.end()); // reverse 는 거꾸로된 문자열을 반환하는게 아니라 인자에 있는 문자열을 직접 조작함.
        if(s == rs)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}