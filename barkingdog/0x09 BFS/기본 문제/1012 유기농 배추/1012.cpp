#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second

bool board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int m, n, k;
        cin >> m >> n >> k;
        while(k--) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        queue<pair<int, int>> Q;
        int cnt = 0;
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                if(!board[y][x] || vis[y][x]) continue;
                vis[y][x] = 1;
                Q.push({y, x});
                cnt++;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int i=0; i<4; i++) {
                        int ny = cur.Y + dy[i];
                        int nx = cur.X + dx[i];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(!board[ny][nx] || vis[ny][nx]) continue;
                        vis[ny][nx] = 1;
                        Q.push({ny, nx});
                    }
                }
            }
        }

        cout << cnt << '\n';

        // 초기화
        for(int y = 0; y < n; y++) {
            fill(board[y], board[y] + m, 0);
            fill(vis[y], vis[y] + m, 0);
        }
    }

    return 0;
}