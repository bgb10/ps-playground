#include <bits/stdc++.h>
using namespace std;

int nxt[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void visit(int x) {
    int cur = x;
    while(true) {
        state[cur] = x;
        cur = nxt[cur];
        if(state[cur] == x) {
            while(state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = nxt[cur];
            }
            return;
        }
        else if(state[cur] != 0) return;
    }
}

// 이렇게 풀려면 직접 그래프를 그려서 경우를 나눠봤어야 한다.
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(int i=1; i<=n; i++)
            cin >> nxt[i];
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(state[i] == NOT_VISITED) visit(i);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}