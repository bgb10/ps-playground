#include <bits/stdc++.h>
using namespace std;

queue<tuple<int, int, int, int>> Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int jx[8] = {-1,-2,1,2,-1,2,1,-2};
int jy[8] = {-2,-1,2,1,2,-1,-2,1};
int board[203][203];
int dist[203][203][33];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, w, h;
    cin >> k >> w >> h;

    for(int x=0; x<h; x++)
        for(int y=0; y<w; y++)
            for(int z=0; z<=k; z++)
                dist[x][y][z] = -1;

    for(int x=0; x<h; x++)
        for(int y=0; y<w; y++)
            cin >> board[x][y];

    
    Q.push({0,0,0,0});
    dist[0][0][0] = 0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int curK = get<2>(cur);
        int curD = get<3>(cur);
        if(curX == h-1 && curY == w-1) {
            cout << curD;
            return 0;
        }
        for(int i=0; i<4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(board[nx][ny]) continue;
            if(dist[nx][ny][curK] != -1) continue;
            dist[nx][ny][curK] = dist[curX][curY][curK] + 1;
            Q.push({nx, ny, curK, curD + 1});
            // cout << "push: " << nx << ":" << ny << ":" << curK << ":dist is" << curK << '\n';
        }
        for(int i=0; i<8; i++) {
            int nx = curX + jx[i];
            int ny = curY + jy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(curK >= k) continue;
            if(board[nx][ny]) continue;
            if(dist[nx][ny][curK + 1] != -1) continue;
            dist[nx][ny][curK + 1] = dist[curX][curY][curK] + 1;
            Q.push({nx, ny, curK + 1, curD + 1});
            // cout << "push: " << nx << ":" << ny << ":" << curK + 1 << ":dist is" << curK << '\n';
        }
    }
    
    // for(int z=0; z<=k; z++) {
    //     for(int x=0; x<h; x++) {
    //         for(int y=0; y<w; y++){
    //             cout << dist[x][y][z] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << "\n\n";
    // }

    cout << -1;

    return 0;
}