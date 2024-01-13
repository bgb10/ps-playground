#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int bf[305][305];
int board[305][305];
bool vis[305][305];
int n, m;

void melt() {
    copy(&board[0][0], &board[0][0]+305*305, &bf[0][0]);

    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {
            if(board[x][y] == 0) continue;
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(bf[nx][ny] == 0)
                    board[x][y]--;
                if(board[x][y] <= 0) {
                    board[x][y] = 0;
                    break;
                }
            }
        }
    }
    // for(int x=0; x<n; x++) {
    //     for(int y=0; y<m; y++) {
    //         cout << board[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int chunk() {
    int cnt = 0;
    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {
            if(board[x][y] == 0 || vis[x][y]) continue;
            queue<pair<int, int>> Q;

            cnt++;
            vis[x][y] = true;
            Q.push({x,y});
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }

            Q = queue<pair<int, int>>();
        }
    }
    for(int i=0; i<n; i++) fill(vis[i], vis[i]+m, 0);

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            cin >> board[x][y];
    int cnt = 0;
    while(true) {
        cnt++;
        melt();
        int glacier = chunk();
        if(glacier == 0) {
            cout << 0;
            return 0;
        }
        if(glacier > 1) {
            cout << cnt;
            return 0;
        }
    }
    return 0;
}