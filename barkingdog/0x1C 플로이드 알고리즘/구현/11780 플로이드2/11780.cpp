/*
플로이드-와샬 알고리즘에서 경로 복원을 위해 nxt 라는 2차원 배열을 추가로 사용했다.

다른 노드를 거쳐갈 경우, 거쳐가는 노드로 가는 경로(즉, nxt 배열의 값)을 넣어주면 된다.

방문하지 못하는 경우를 반드시 별도 처리 해주자.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int nxt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + n + 1, 0x3f3f3f3f);
    }
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        if (dp[s][t] > c) {
            dp[s][t] = c;
            nxt[s][t] = t;
        }
    }

    for (int v = 1; v <= n; v++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] > dp[i][v] + dp[v][j]) {
                    dp[i][j] = dp[i][v] + dp[v][j];
                    nxt[i][j] = nxt[i][v];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == 0x3f3f3f3f)
                cout << 0 << ' ';
            else
                cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dp[i][j] == 0x3f3f3f3f)
                cout << 0 << '\n';
            else {
                vector<int> routes = {i};
                int cur = i;
                while (cur != j) {
                    cur = nxt[cur][j];
                    routes.push_back(cur);
                }
                cout << routes.size() << ' ';
                for (int route : routes) {
                    cout << route << ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}