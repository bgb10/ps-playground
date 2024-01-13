#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> D;
    int n;
    cin >> n;

    while(n--) {
        string cmd;
        int x;
        cin >> cmd;
        if(cmd == "push_back") {
            cin >> x;
            D.push_back(x);
        } else if(cmd == "push_front") {
            cin >> x;
            D.push_front(x);
        } else if(cmd == "pop_back") {
            if(D.empty()) {
                cout << -1 << '\n';
            } else {
                cout << D.back() << '\n';
                D.pop_back();
            }
        } else if(cmd == "pop_front") {
            if(D.empty()) {
                cout << -1 << '\n';
            } else {
                cout << D.front() << '\n';
                D.pop_front();
            }
        } else if(cmd == "size") {
            cout << D.size() << '\n';
        } else if(cmd == "empty") {
            cout << (int)D.empty() << '\n';
        } else if(cmd == "front") {
            cout << (D.empty() ? -1 : D.front()) << '\n';
        } else {
            cout << (D.empty() ? -1 : D.back()) << '\n';
        }
    }

    return 0;
}