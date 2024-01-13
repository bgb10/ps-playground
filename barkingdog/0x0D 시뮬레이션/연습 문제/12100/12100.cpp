/* 
구현 문제는 조건을 잘 맞추는 것이 중요하기 때문에 
내부 로직을 직접 출력해보면서 문제를 찾아보고, 테스트케이스도 직접 만들어보자.
특이한 케이스에서 보통 오류가 난다.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int board[22][22];
int temp[22][22];
int mx = 0;
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isadded[22][22];

void printBoard() {
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            cout << board[x][y] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool ismovable(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n) return false; // 벽에 맞닿아있는 경우 불가능
    if(board[nx][ny] == 0) return true; // 다음 칸이 비어있는 경우 가능
    if(board[nx][ny] != board[x][y]) return false; // 다음 칸의 숫자와 지금 숫자가 다른 경우 불가능
    if(isadded[nx][ny] || isadded[x][y]) return false; // 다음 칸의 숫자와 같지만 현재 숫자 또는 다음 칸의 숫자가 더해진 적이 있는 경우 불가능
    return true;
}

void move(int& x, int& y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    // 다음 칸이 비어있는 경우
    if(board[nx][ny] == 0) {
        board[nx][ny] = board[x][y];
        isadded[nx][ny] = isadded[x][y]; // 주의! 이전 칸의 기록을 모두 그대로 옮겨야 함.
        board[x][y] = 0;
        isadded[x][y] = 0;
    }
    // 다음 칸에 합쳐진 적이 없는 같은 값이 있는 경우
    else if (board[nx][ny] == board[x][y]) {
        board[nx][ny] += board[x][y];
        board[x][y] = 0;
        isadded[nx][ny] = 1;
    }

    x = nx;
    y = ny;
}

void up() {
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            if(board[x][y] == 0) continue;
            int curX = x;
            int curY = y;
            while(ismovable(curX, curY, UP)) {
                move(curX, curY, UP);
            }
                
        }
    }
}

void down() {
    for(int x=n-1; x>=0; x--) {
        for(int y=0; y<n; y++) {
            if(board[x][y] == 0) continue;
            int curX = x;
            int curY = y;
            while(ismovable(curX, curY, DOWN)) 
                move(curX, curY, DOWN);
        }
    }
}

void left() {
    for(int y=0; y<n; y++) {
        for(int x=0; x<n; x++) {
            if(board[x][y] == 0) continue;
            int curX = x;
            int curY = y;
            while(ismovable(curX, curY, LEFT)) {
                move(curX, curY, LEFT);
            }
                
        }
    }
}

void right() {
    for(int y=n-1; y>=0; y--) {
        for(int x=0; x<n; x++) {
            if(board[x][y] == 0) continue;
            int curX = x;
            int curY = y;
            while(ismovable(curX, curY, RIGHT)) 
                move(curX, curY, RIGHT);
        }
    }
}

int getCurrentMaxBlock() {
    int tmx = 0;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            tmx = max(tmx, board[x][y]);
        }
    }
    
    return tmx;
}

void clearFix() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            isadded[i][j] = 0;
        }
    }
}

void backUp() {
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            board[x][y] = temp[x][y];
        }
    }
}

int main()
{
    cin >> n;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            cin >> board[x][y];
            temp[x][y] = board[x][y];
        }
    }
    // 1024 는 4^5 의미
    for(int i=0; i<1024; i++) {
        int tmp = i;
        for(int j=0; j<5; j++) {
            int flag = tmp % 4;
            if(flag == 0) up();
            else if(flag == 1) down();
            else if(flag == 2) left();
            else if(flag == 3) right();
            tmp >>= 2;
            clearFix();
        }
        // 현재 경우에 따른 최대 블록 계산 및 전체 경우의 수에 대해 최대 값 찾기
        mx = max(mx, getCurrentMaxBlock());
        backUp();
    }

    cout << mx;
    return 0;
}