#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int M;
    char cmd;
    list<char> L = {};

    cin >> s >> M;
    for(auto c : s) {
        L.push_back(c);
    }
    auto cursor = L.end(); //operator의 end는 마지막 원소의 '다음'을 가리킴

    for(int i=0; i<M; i++) {
        cin >> cmd;

        // operator 에 증감연산자를 사용하면 nxt, prev 로 이동
        if(cmd == 'L') {
            if(cursor != L.begin()) cursor--;
        } else if(cmd == 'D') {
            if(cursor != L.end()) cursor++;
        } else if(cmd == 'B') {
            if(cursor != L.begin()) {
                /* L.erase(--cursor); erase 에서 반환된 값을 받지 않고 그냥 이것만 하면 해제된 메모리 영역에
                접근하게 된다. */
                cursor = L.erase(--cursor); // 메모리 해제 되어있어서 안되는듯?
            }
        } else {
            cin >> cmd;
            L.insert(cursor, cmd);
        }
    }

    for(auto lit : L) {
        cout << lit;
    }

    return 0;
}