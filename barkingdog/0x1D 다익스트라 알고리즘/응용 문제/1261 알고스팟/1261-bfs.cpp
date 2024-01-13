/*
BFS 도중에 벽을 뚫을 수 있는 흔한 유형의 문제다. 벽을 뚫은 횟수를 저장하기 위해 3차원 배열을 사용한다.

이때 먼저 도착한다고 bfs를 멈추면(while문을 빠져나오면) 안된다.
벽을 최소한으로 뚫어야 하는데, 벽을 여러번 뚫는 경우에 벽을 최소한으로 뚫고 가는 경우보다 더 빨리 도착할 수도 있기
때문이다. 그리고 벽 뚫기를 할 때 방문 여부를 체크하지 않으면 MLE 가 날 수 있으니 조심하자.

# 흔한 유형의 문제다. 2206, 1600 번을 풀어보자.
# 다익스트라, 0-1 BFS 로도 풀이할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool board[105][105];
bool vis[205][105][105];  // z y x

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    queue<tuple<int, int, int>> Q;
    vis[0][0][0] = 1;
    Q.push({0, 0, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int cz, cy, cx;
        tie(cz, cy, cx) = cur;
        for (int i = 0; i < 4; i++) {
            int nz = cz;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (vis[nz][ny][nx]) continue;
            if (board[ny][nx]) {
                if (nz > 200) continue;
                nz++;                           // 벽 뚫기
                if (vis[nz][ny][nx]) continue;  // 방문 여부 체크
            }
            vis[nz][ny][nx] = 1;
            Q.push({nz, ny, nx});
        }
    }
    for (int cnt = 0; cnt < 200; cnt++) {
        if (vis[cnt][n - 1][m - 1]) {
            cout << cnt;
            break;
        }
    }
    return 0;
}