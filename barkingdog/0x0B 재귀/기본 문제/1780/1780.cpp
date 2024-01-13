#include <bits/stdc++.h>
using namespace std;

int board[(int)pow(3, 7) + 2][(int)pow(3, 7) + 2];
int n;

int m;
int z;
int p;

void check(int a, int b) {
    if(board[a][b] == -1) m++;
        else if(board[a][b] == 0) z++;
        else p++;
}

void paper(int n, int a, int b) {
    if(n==1) {
        check(a, b);
    } else {
        for(int x=a; x<a+n; x++) {
            for(int y=b; y<b+n; y++) {
                if(board[x][y] != board[a][b]) {
                    int delta = n / 3;
                    for(int i=0; i<3; i++) {
                        for(int j=0; j<3; j++) {
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
    cout << m << '\n' << z << '\n' << p << '\n';

    return 0;
}