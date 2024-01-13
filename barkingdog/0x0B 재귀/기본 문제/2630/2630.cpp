#include <bits/stdc++.h>
using namespace std;

int board[(int)pow(2, 7) + 2][(int)pow(2, 7) + 2];
int n;

int wh;
int bl;

void check(int a, int b) {
    if(board[a][b] == 0) wh++;
    else bl++;
}

void paper(int n, int a, int b) {
    if(n==1) {
        check(a, b);
    } else {
        for(int x=a; x<a+n; x++) {
            for(int y=b; y<b+n; y++) {
                if(board[x][y] != board[a][b]) {
                    int delta = n / 2;
                    for(int i=0; i<2; i++) {
                        for(int j=0; j<2; j++) {
                            paper(delta, a + i * delta, b + j * delta);
                        }
                    }
                    return;
                }
            }
        }

        check(a, b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            cin >> board[x][y];
    paper(n, 0, 0);
    cout << wh << '\n' << bl;

    return 0;
}