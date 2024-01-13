#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
#define X first
#define Y second
int board[SIZE][SIZE];
int vis[SIZE][SIZE];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
queue<pair<int, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int x=0; x<n; x++)
    for(int y=0; y<m; y++) {
        cin >> board[x][y];
        if(board[x][y] != 1) 
            vis[x][y] = -1;
        else {
            vis[x][y] = 0;
            Q.push({x, y});
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == -1) continue;
            if(vis[nx][ny] != -1) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny}); 
        }
    }
    int mx = INT_MIN;
    for(int x=0; x<n; x++)
    for(int y=0; y<m; y++) {
        if(board[x][y] != -1 && vis[x][y] == -1) {
            cout << -1;
            return 0;
        }
        mx = max(mx, vis[x][y]);
    }
    cout << mx;
    return 0;
}