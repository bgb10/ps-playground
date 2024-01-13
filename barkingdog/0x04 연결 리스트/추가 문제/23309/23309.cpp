#include <bits/stdc++.h>
using namespace std;

const int MX = 2000005;
int pre[MX], nxt[MX];
bool dat[MX];
int n, m;

void insert(int addr, int k) { // k는 고유번호
    dat[k] = 1;
    pre[k] = addr;
    nxt[k] = nxt[addr];
    pre[nxt[addr]] = k;
    nxt[addr] = k;
}

void erase(int addr) {
    dat[addr] = 0;
    nxt[pre[addr]] = nxt[addr];
    pre[nxt[addr]] = pre[addr];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // 첫번째 역 넣기
    int i,j;
    cin >> j;
    dat[j] = 1;
    int first = j;
    int bf = j;
    for(int k=0; k<n-1; k++) {
        cin >> j;
        dat[j] = 1;
        pre[j] = bf;
        nxt[bf] = j;
        bf = j;
    }
    nxt[bf] = first;
    pre[first] = bf;
    string cmd;
    getline(cin, cmd); //개행 제거(cin 은 개행 문자를 받지 않는다. 따라서 getline 으로 개행문자를 처리해야 함.)
    for(int k=0; k<m; k++) {
        cin >> cmd;
        if(cmd == "BN") {
            cin >> i >> j;
            cout << nxt[i];
            insert(i, j);
        } else if(cmd == "BP") {
            cin >> i >> j;
            cout << pre[i];
            insert(pre[i], j);
        } else if(cmd == "CN") {
            cin >> i;
            cout << nxt[i];
            erase(nxt[i]);
        } else { // CP
            cin >> i;
            cout << pre[i];
            erase(pre[i]);
        }
        cout << '\n';
        cmd = "";
    }
    return 0;
}