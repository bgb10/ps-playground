#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[10][10];
bool visible[10][10];

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int rotateD[4] = {0, 1, 2, 3};
int cctvC = 0;
int cctvRotate[10];
int mn = INT_MAX;

void see(int stX, int stY, int dir) {
    int dx = 0, dy = 0;
    
    if(dir % 4 == UP) {
        dx = -1;
    }
    else if(dir % 4 == RIGHT) {
        dy = 1;
    }
    else if(dir % 4 == DOWN) {
        dx = 1;
    }
    else {
        dy = -1;
    }
    
    for(int x = stX, y = stY; ; x += dx, y += dy) {
        if(x < 0 || x >= n || y < 0 || y >= m) break;
        if(board[x][y] == 6) break;
        visible[x][y] = 1;
    }
}

void solve(int k) {
    if(k == cctvC) {
        int cctvCur = 0;
        for(int x=0; x<n; x++) {
            for(int y=0; y<m; y++) {
                if(board[x][y] != 0 && board[x][y] != 6) {
                    if(board[x][y] == 1) {
                        see(x, y, RIGHT + cctvRotate[cctvCur]);
                    }
                    else if(board[x][y] == 2) {
                        see(x, y, LEFT + cctvRotate[cctvCur]);
                        see(x, y, RIGHT + cctvRotate[cctvCur]);
                    }
                    else if(board[x][y] == 3) {
                        see(x, y, UP + cctvRotate[cctvCur]);
                        see(x, y, RIGHT + cctvRotate[cctvCur]);
                    }
                    else if(board[x][y] == 4) {
                        see(x, y, LEFT + cctvRotate[cctvCur]);
                        see(x, y, UP + cctvRotate[cctvCur]);
                        see(x, y, RIGHT + cctvRotate[cctvCur]);
                    }
                    else if(board[x][y] == 5) {
                        see(x, y, LEFT + cctvRotate[cctvCur]);
                        see(x, y, UP + cctvRotate[cctvCur]);
                        see(x, y, RIGHT + cctvRotate[cctvCur]);
                        see(x, y, DOWN + cctvRotate[cctvCur]);
                    }
                    cctvCur++;
                }
            }
        }

        int cnt = 0;
        for(int x=0; x<n; x++) {
            for(int y=0; y<m; y++) {
                if(visible[x][y] == 0 && board[x][y] != 6) {
                    cnt++;
                }
            }
        }
        
        mn = min(mn, cnt);
        
        for(int x=0; x<n; x++) {
            for(int y=0; y<m; y++) {
                visible[x][y] = 0;
            }
        }
        
        return;
    }

    for(int i : rotateD) {
        cctvRotate[k] = i;
        solve(k+1);
    }
}

int main()
{
    cin >> n >> m;
    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {
            cin >> board[x][y];
            if(board[x][y] != 0 && board[x][y] != 6) {
                cctvC++;
            }
        }
    }
    solve(0);
    cout << mn;
    return 0;
}