#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int r, c, t;

int board[52][52];
int temp[52][52];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int countMise() {
    int cnt = 0;

    for(int x=0; x<r; x++) {
        for(int y=0; y<c; y++) {
            if(board[x][y] != -1)
                cnt += board[x][y];
        }
    }
    
    return cnt;
}

void printTemp() {
            for(int x=0; x<r; x++) {
            for(int y=0; y<c; y++) {
                cout << temp[x][y] << ' ';
            }
            cout << '\n';
        }
}

void printBoard() {
            for(int x=0; x<r; x++) {
            for(int y=0; y<c; y++) {
                cout << board[x][y] << ' ';
            }
            cout << '\n';
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> t;
    pair<int, int> acu = {-1, -1};
    pair<int, int> acd = {-1, -1};
    for(int x=0; x<r; x++) {
        for(int y=0; y<c; y++) {
            cin >> board[x][y];
            if(board[x][y] == -1) {
                if(acu.X == -1) {
                    acu.X = x;
                    acu.Y = y;
                }
                else {
                    acd.X = x;
                    acd.Y = y;
                }
            }
        }
    }
    while(t--) {
        // 퍼지기
        for(int x=0; x<r; x++) {
            for(int y=0; y<c; y++) {
                if(board[x][y] == -1) continue;
                int t = board[x][y];
                int spread = board[x][y] / 5;
                int spreaded = 0;
                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if(board[nx][ny] == -1) continue;
                    temp[nx][ny] += spread;
                    spreaded += spread;
                }
                t -= spreaded;
                temp[x][y] += t;
            }
        }

        // cout << "확산\n\n";
        // printTemp();

        // 공기청정기
        // up
        temp[acu.X][acu.Y] = 0;
        for(int i=acu.X; i>0; i--) {
            temp[i][0] = temp[i-1][0];
        }
        for(int i=0; i<c-1; i++) {
            temp[0][i] = temp[0][i+1];
        }
        for(int i=0; i<acu.X; i++) {
            temp[i][c-1] = temp[i+1][c-1];
        }
        for(int i=c-1; i>0; i--) {
            temp[acu.X][i] = temp[acu.X][i-1];
        }
        temp[acu.X][acu.Y+1] = 0;
        temp[acu.X][acu.Y] = 0;

        //down
        temp[acd.X][acd.Y] = 0;
        for(int i=acd.X; i<r-1; i++) {
            temp[i][0] = temp[i+1][0];
        }
        for(int i=0; i<c-1; i++) {
            temp[r-1][i] = temp[r-1][i+1];
        }
        for(int i=r-1; i>acd.X; i--) {
            temp[i][c-1] = temp[i-1][c-1];
        }
        for(int i=c-1; i>0; i--) {
            temp[acd.X][i] = temp[acd.X][i-1];
        }
        temp[acd.X][acd.Y+1] = 0;
        temp[acd.X][acd.Y] = 0;


        // cout << "이동\n\n";
        // printTemp();

        for(int x=0; x<r; x++) {
            for(int y=0; y<c; y++) {
                if(x == acu.X && y == acu.Y) continue;
                if(x == acd.X && y == acd.Y) continue;
                board[x][y] = temp[x][y];
            }
        }
        for(int x=0; x<r; x++)
        for(int y=0; y<c; y++)
            temp[x][y] = 0;

        // cout << "보드\n\n";
        // printBoard();
    }
    
    cout << countMise();

    return 0;
}