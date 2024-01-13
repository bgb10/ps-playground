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

int main()
{
    cin >> n;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            cin >> board[x][y];
        }
    }
    int k = 1 << n;
    for(int i=0; i<k; i++) {
        int flag = 1;
        for(int x=0; x<n; x++) {
            if(i & flag) {
                flipX(x);
                cnt++;
            }
            flag = flag << 1;
        }
        for(int j=0; j<k; j++) {
            int flag2 = 1;
            for(int y=0; y<n; y++) {
                if(j & flag2) {
                    flipY(y);
                    cnt++;
                }
                flag2 = flag2 << 1;
            }
            count();
            flag2 = 1;
            for(int y=0; y<n; y++) {
                if(j & flag2) {
                    flipY(y);
                    cnt--;
                }
                flag2 = flag2 << 1;
            }
        }
        flag = 1;
        for(int x=0; x<n; x++) {
            if(i & flag) {
                flipX(x);
                cnt--;
            }
            flag = flag << 1;
        }
    }
    cout << mn;
    return 0;
}