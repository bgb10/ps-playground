#include <bits/stdc++.h>
using namespace std;

int state[100005];
int nxt[100005];

const int NOT_VISITED = -1;
const int CYCLE_IN = 1;
const int CYCLE_OUT = 0;
const int VISITING = -2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        fill(state, state+100005, NOT_VISITED);
        fill(nxt, nxt+100005, 0);

        int n;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> nxt[i];
        for(int i=1; i<=n; i++) {
            if(state[i] != NOT_VISITED) continue;
            state[i] = VISITING;
            int cur = nxt[i];
            // 방문한 곳을 재방문 할때까지 순회
            bool recycle = false;
            while(state[cur] != VISITING) {
                // 순회 이전에 방문했던 곳을 방문할 경우, 자동으로 여태 순회했던 노드들은 사이클에 포함되지 않음
                if(state[cur] != NOT_VISITED) {
                    recycle = true;
                    break;
                }
                state[cur] = VISITING;
                cur = nxt[cur];
            }

            if(recycle) {
                int cur2 = i;
                while(cur2 != cur) {
                    state[cur2] = CYCLE_OUT;
                    cur2 = nxt[cur2];
                }
                continue;
            }

            int no_state = i;
            while(no_state != cur) {
                state[no_state] = CYCLE_OUT;
                no_state = nxt[no_state];
            }

            int yes_state = cur;
            state[yes_state] = CYCLE_IN;
            yes_state = nxt[yes_state];
            while(yes_state != cur) {
                state[yes_state] = CYCLE_IN;
                yes_state = nxt[yes_state];
            }
        }

        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(state[i] == 0) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}