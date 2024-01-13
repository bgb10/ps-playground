#include <bits/stdc++.h>
#define SIZE 5
#define GONGJU 7
using namespace std;

char board[SIZE+2][SIZE+2];
bool vis[SIZE+2][SIZE+2];
int sc, yc; // 와,,, 변수명 겹치는거 실화냐
int sx, sy;
int cnt;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void visit(int x, int y) {
    vis[x][y] = 1;
    if(board[x][y] == 'S') sc++;
    else yc++;
}
void unvisit(int x, int y) {
    vis[x][y] = 0;
    if(board[x][y] == 'S') sc--;
    else yc--;
}
void solve(int x, int y) {
    if(x == 3 && y == 1)
        cout << "count: " << x << ' ' << y << '\n';
    if(sc + yc == 7) {
        if(sc >= 4) {
            cnt++;
            cout << x << ' ' << y << '\n';
        } 
        return;
    }
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
        if(nx < sx) continue;
        if(nx == sx && ny < sy) continue;
        if(vis[nx][ny]) continue;
        visit(nx, ny);
        solve(nx, ny);
        unvisit(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int x=0; x<SIZE; x++)
        for(int y=0; y<SIZE; y++)
            cin >> board[x][y];
    // for(int x=0; x<SIZE; x++)
    //     for(int y=0; y<SIZE; y++) {
    //         sx = x; sy = y;
    //         visit(x, y);
    //         solve(x, y);
    //         unvisit(x, y);
    //         sc = 0; yc = 0;
    //     }
    sx = 1; sy = 0;
    visit(1, 0);
    solve(1, 0);
    // 아,, DFS 라서 탐색한 길을 다시 돌아오는구나
    cout << cnt;
    return 0;
}