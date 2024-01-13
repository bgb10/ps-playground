#include <bits/stdc++.h>
using namespace std;

char board[(int)pow(3, 8) + 2][(int)pow(3, 8) + 2];
int n;

void empty(int n, int a, int b) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            board[a + i][b + j] = ' ';
    }
}

void star(int n, int a, int b) {
    if(n==1) {
        board[a][b] = '*';
        return;
    }
    int d = n / 3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i == 1 && j == 1) {
                empty(d, a + d, b + d);
                continue;
            }
            star(d, a + i * d, b + j * d);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    star(n, 0, 0);
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            cout << board[x][y];
        }
        cout << '\n';
    }

    return 0;
}