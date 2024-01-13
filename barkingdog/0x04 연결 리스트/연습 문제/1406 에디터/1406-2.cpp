#include <bits/stdc++.h>
using namespace std;

string s;
int m;
list<char> L = {};
char cmd;
char nc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> m;
    for(char c : s)
        L.push_back(c);
    auto cursor = L.end(); // L.end() 를 통해 반환된 iterator는 마지막 노드의 다음을 가리킴
    for(int i=0; i<m; i++) {
        cin >> cmd;
        if(cmd == 'L') {
            if(cursor != L.begin())
                cursor--;
        } else if(cmd == 'D') {
            if(cursor != L.end())
                cursor++;
        } else if(cmd == 'B') {
            if(cursor != L.begin())
                cursor = L.erase(--cursor);
        } else {
            cin >> nc;
            L.insert(cursor, nc);
        }
    }
    for(auto lit : L)
        cout << lit;
    return 0;
}