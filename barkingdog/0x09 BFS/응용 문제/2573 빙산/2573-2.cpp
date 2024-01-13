#include <bits/stdc++.h>
using namespace std;
#define SIZE 302
#define X first
#define Y second

int board[SIZE][SIZE];
int temp[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int t = 0;
int n, m;

void solve() {
    t++;

    for(int x=0; x<n; x++)
    for(int y=0; y<m; y++)
        temp[x][y] = board[x][y];

    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {
            if(temp[x][y] == 0) continue;
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(temp[nx][ny] != 0) continue;
                board[x][y]--;
                if(board[x][y] == 0) break;
            }
        }
    }       
    
    int cnt = 0;
    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {
            if(board[x][y] == 0 || vis[x][y]) continue;
            cnt++;
            queue<pair<int, int>> Q;
            Q.push({x, y});
            vis[x][y] = 1;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    for(int x=0; x<n; x++)
    for(int y=0; y<m; y++) {
        vis[x][y] = 0;
    }

    if(cnt == 1) solve();
    else {
        if(cnt == 0)
            cout << 0;
        else
            cout << t;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int x=0; x<n; x++)
    for(int y=0; y<m; y++)
        cin >> board[x][y];
    solve();
    return 0;
}