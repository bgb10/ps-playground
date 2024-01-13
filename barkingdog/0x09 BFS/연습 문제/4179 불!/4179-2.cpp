#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
#define X first
#define Y second
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int r, c;
bool board[SIZE][SIZE];
int dist1[SIZE][SIZE];
int dist2[SIZE][SIZE];
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

// 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
    }
    for(int x=0; x<r; x++)
    for(int y=0; y<c; y++) {
        char e;
        cin >> e;
        if(e == 'J') {
            dist1[x][y] = 0;
            Q1.push({x, y});
            board[x][y] = 1;
        }
        else if(e == 'F') {
            dist2[x][y] = 0;
            Q2.push({x, y});
        }
        else if(e == '.') {
            board[x][y] = 1;
        }
        else {
            board[x][y] = 0;
        }
    }
    // FIRE
    while(!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(dist2[nx][ny] != -1) continue;
            if(!board[nx][ny]) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    // JIHOON
    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << dist1[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist1[nx][ny] != -1) continue;
            if(!board[nx][ny]) continue;
            // 불이 -1 인지 반드시 체크!
            if(dist2[nx][ny] != -1 && dist1[cur.X][cur.Y] + 1 >= dist2[nx][ny]) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}