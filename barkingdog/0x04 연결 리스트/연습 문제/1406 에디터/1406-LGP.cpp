#include <bits/stdc++.h>

using namespace std;

list<char> L;

int main() {
    string s;
    int n;
    cin >> s >> n;
    for (char c : s) {
        L.push_back(c);
    }
    auto cursor = L.end();
    while (n--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor != L.begin()) cursor--;
        } else if (cmd == 'D') {
            if (cursor != L.end()) cursor++;
        } else if (cmd == 'B') {
            if (cursor != L.begin()) {
                cursor--; // 맨 뒤에 있는 것을 생각해봐, 이전으로 가야겠지?
                cursor = L.erase(cursor);
            }
        } else if (cmd == 'P') {
            char d;
            cin >> d;
            L.insert(cursor, d);
        }
    }
    for(auto lit : L) {
        cout << lit;
    }
    return 0;
}