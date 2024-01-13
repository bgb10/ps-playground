#include <bits/stdc++.h>
using namespace std;
#define SIZE 102
#define X first
#define Y second

int board[SIZE][SIZE];
bool safe[SIZE][SIZE];
bool vis[SIZE][SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int mx = INT_MIN;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            cin >> board[x][y];
    for(int h=0; h<=101; h++) {
        for(int x=0; x<n; x++)
            for(int y=0; y<n; y++) {
                if(board[x][y] <= h)
                    safe[x][y] = false;
                else
                    safe[x][y] = true;
            }
        int cnt = 0;
        queue<pair<int, int>> Q;
        for(int x=0; x<n; x++)
            for(int y=0; y<n; y++) {
                if(safe[x][y] && !vis[x][y]) {
                    cnt++;
                    // BFS
                    Q.push({x, y});
                    vis[x][y] = true;
                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for(int i=0; i<4; i++) {
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if(!safe[nx][ny]) continue;
                            if(vis[nx][ny]) continue;
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }
                }
            }

        mx = max(mx, cnt);
        cnt = 0;
        
        for(int x=0; x<n; x++)
            for(int y=0; y<n; y++)
                vis[x][y] = false;

    }
    cout << mx;

    return 0;
}