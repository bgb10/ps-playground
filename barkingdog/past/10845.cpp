#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int x;
        if(s == "push") {
            cin >> x;
            Q.push(x);
        } else if(s == "front") {
            cout << (Q.empty() ? -1 : Q.front()) << '\n';
        } else if(s == "back") {
            cout << (Q.empty() ? -1 : Q.back()) << '\n';
        } else if(s == "size") {
            cout << Q.size() << '\n';
        } else if(s == "empty") {
            cout << (int)Q.empty() << '\n';
        } else { //pop
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
    }

    return 0;
}