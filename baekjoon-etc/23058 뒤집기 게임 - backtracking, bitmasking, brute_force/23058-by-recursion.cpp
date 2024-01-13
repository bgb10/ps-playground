#include <bits/stdc++.h>

using namespace std;

int n;
int mn = INT_MAX;
int board[10][10];
int cnt = 0;

void count() {
    int b = 0;
    int w = 0;
    
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            if(board[x][y] == 0) b++;
            else w++;
        }
    }
    
    mn = min(mn, ((b < w) ? b : w) + cnt);
}

void flipY(int stY) {
    for(int x=0; x<n; x++)
        board[x][stY] = !board[x][stY];
}

void flipX(int stX) {
    for(int y=0; y<n; y++)
        board[stX][y] = !board[stX][y];
}

void solve(int k) {
    if(k == n) {
        count();
        return;
    }
    // flip nothing
    solve(k+1);
    // flip X
    flipX(k); cnt++;
    solve(k+1);
    flipX(k); cnt--;
    // flip Y
    flipY(k); cnt++;
    solve(k+1);
    flipY(k); cnt--;
    // flip X and Y
    flipX(k); cnt++;
    flipY(k); cnt++;
    solve(k+1);
    flipX(k); cnt--;
    flipY(k); cnt--;
}

int main()
{
    cin >> n;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            cin >> board[x][y];
        }
    }
    solve(0);
    cout << mn;
    return 0;
}