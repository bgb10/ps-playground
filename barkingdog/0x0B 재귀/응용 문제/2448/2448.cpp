#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3 * (2 << 10) + 2;

char board[SIZE][SIZE];

void star(int n, int a, int b) {
    if(n == 3) {
        board[a][b] = '*';
        board[a+1][b-1] = board[a+1][b+1] = '*';
        for(int i=b-2; i<=b+2; i++) board[a+2][i] = '*';
        return;
    } 
    int div = n/2;
    star(div, a + div, b - div);
    star(div, a, b);
    star(div, a + div, b + div);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int x=0; x<SIZE; x++) fill(board[x], board[x] + SIZE, ' ');
    int n;
    cin >> n;
    star(n, 0, n-1);
    for(int x=0; x<n; x++) {
        for(int y=0; y<n*2-1; y++) {
            cout << board[x][y];
        }
        cout << '\n';
    }
    return 0;
}