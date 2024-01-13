#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    // 인접한 노드로 이동하는게 많으니까, 연결리스트
    // 그리고 중간에 삽입 삭제가 많음. 연결리스트
    list<char> password = {};
    auto cursor = password.end();

    for(int i=0; i<T; i++) {
        string input;
        cin >> input;

        list<char> password = {};
        auto cursor = password.end();

        for(auto c : input) {
            if(c == '<') {
                if(cursor != password.begin()) cursor--;
            } else if(c == '>') {
                if(cursor != password.end()) cursor++;
            } else if(c == '-') {
                if(cursor != password.begin()) {
                    cursor = password.erase(--cursor);
                }
            } else {
                password.insert(cursor, c);
            }
        }

        for(auto c : password) cout << c;

        cout << "\n";
    }

    return 0;
}