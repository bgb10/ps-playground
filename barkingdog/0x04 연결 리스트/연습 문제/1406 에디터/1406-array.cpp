#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX]; // -1로 초기화
int unused = 1;

// 이거 자체는 순회가 필요 없이 O(1) 이어야지.
// 애초에 list 상의 주소를 준거기 때문에 내가 연산할 필요가 없다...
void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1) {
    pre[nxt[addr]] = unused;
  }
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  if(nxt[addr] != -1) {
    pre[nxt[addr]] = pre[addr];
  }
  nxt[pre[addr]] = nxt[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string init;
    cin >> init;

    int cursor = 0; // list 의 iterator 에 대응
    for(auto c : init) {
        insert(cursor, c);
        cursor++;
    }
    int q;
    cin >> q;
    while (q--) {
        char cmd;
        cin >> cmd;

        if(cmd == 'L') {
            if(pre[cursor] != -1) cursor = pre[cursor];
        } else if(cmd == 'D') {
            if(nxt[cursor] != -1) cursor = nxt[cursor];
        } else if(cmd == 'B') {
            if(pre[cursor] != -1) {
                erase(cursor);
                cursor = pre[cursor];
            }
        } else {
            char add;
            cin >> add;
            insert(cursor, add);
            cursor = nxt[cursor];
        }
    }

    traverse();

    return 0;
}