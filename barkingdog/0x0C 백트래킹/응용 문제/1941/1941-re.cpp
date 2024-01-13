#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

char board[SIZE+2][SIZE+2];
bool vis[SIZE+2][SIZE+2];
int sc, yc; // 와,,, 변수명 겹치는거 실화냐
int cnt;
int dx[4] = {0, 1, 0, -1}; //위로 가는건 없다.
int dy[4] = {1, 0, -1, 0};

void solve(int x, int y) {
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int x=0; x<SIZE; x++)
        for(int y=0; y<SIZE; y++)
            cin >> board[x][y];
    for(int x=0; x<SIZE; x++)
        for(int y=0; y<SIZE; y++)
            solve(x, y);
    return 0;
}