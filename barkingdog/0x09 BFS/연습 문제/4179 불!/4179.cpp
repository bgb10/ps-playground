#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int j[1002][1002];
int f[1002][1002];
int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 데이터를 -1로 할지, 0으로 할지, 1로 할지 잘 정해라.
    // board: 벽 -1, 지나간적 x 0
    // j: 방문 x -1, 방문 o -> 0 이상
    // h: 같음
    queue<pair<int, int>> JQ;
    queue<pair<int, int>> FQ;

    cin >> r >> c;
    for(int x = 0; x < r; x++) {
        for(int y = 0; y < c; y++) {
            j[x][y] = -1;
            f[x][y] = -1;
            
            char block;
            cin >> block;
            if(block == '#') {
                board[x][y] = -1;
            } else if(block == '.') {
                board[x][y] = 0; 
            } else if(block == 'J') {
                j[x][y] = 0;
                JQ.push({x, y});
            } else if(block == 'F') {
                f[x][y] = 0;
                FQ.push({x, y});
            }
        }
    }

    while(!JQ.empty()) {
        pair<int, int> cur = JQ.front(); JQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == -1) continue; // 벽 pass
            if(j[nx][ny] != -1) continue; // 지나온 공간 pass

            j[nx][ny] = j[cur.X][cur.Y] + 1;
            JQ.push({nx, ny});
        }
    }

    while(!FQ.empty()) {
        pair<int, int> cur = FQ.front(); FQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == -1) continue; // 벽 pass
            if(f[nx][ny] != -1) continue;

            f[nx][ny] = f[cur.X][cur.Y] + 1;
            FQ.push({nx, ny});
        }
    }

    int mn = INT_MAX;
    for(int x=0, y=0; x<r; x++) {
        if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
            mn = min(mn, j[x][y]);
        }
    }
    for(int x=0, y=c-1; x<r; x++) {
        if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
            mn = min(mn, j[x][y]);
        }
    }
    for(int x=0, y=0; y<c; y++) {
        if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
            mn = min(mn, j[x][y]);
        }
    }
    for(int x=r-1, y=0; y<c; y++) {
        if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
            mn = min(mn, j[x][y]);
        }
    }

    if(mn == INT_MAX) {
        cout << "IMPOSSIBLE";
    } else {
        cout << mn + 1;
    }

    return 0;
}