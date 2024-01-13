#include <bits/stdc++.h>
using namespace std;

char board[600000];

void solve(int st, int k) {
    if(k == 1) {
        board[st] = '-';
        return;
    }
    solve(st, k/3);
    solve(st + 2 * (k/3), k/3);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int n;
        cin >> n;
        if(cin.eof())
            break;
        int k = (int)pow(3, n);
        fill(board, board+k, ' ');
        solve(0, k);
        for(int i=0; i<k; i++)
            cout << board[i];
        cout << '\n';
    }
    return 0;
}