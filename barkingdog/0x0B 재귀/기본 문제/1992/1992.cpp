#include <bits/stdc++.h>
using namespace std;

int board[(int)pow(2, 7) + 2][(int)pow(2, 7) + 2];
int n;

void quadTree(int n, int a, int b) {
    if(n==1) {
        cout << board[a][b];
    } else {
        for(int x=a; x<a+n; x++) {
            for(int y=b; y<b+n; y++) {
                if(board[x][y] != board[a][b]) {
                    int delta = n / 2;
                    cout << '(';
                    for(int i=0; i<2; i++) {
                        for(int j=0; j<2; j++) {
                            quadTree(delta, a + i * delta, b + j * delta);
                        }
                    }
                    cout << ')';
                    return;
                }
            }
        }
        cout << board[a][b];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int x=0; x<n; x++) {
        string s;
        cin >> s;
        for(int y=0; y<n; y++)
            board[x][y] = s[y] - '0';
    }
    quadTree(n, 0, 0);

    return 0;
}