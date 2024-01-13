#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;

bool isused1[40];
bool isused2[40];
bool isused3[40];

bool board[16][16];

void queen(int k) {
    if(k == n) {
        cnt++;
        return;
    }
    for(int i=0; i<n; i++) {
        if(isused1[i] || isused2[k+i] || isused3[k-i+n-1]) continue;
        board[k][i] = true;
        isused1[i] = true;
        isused2[k+i] = true;
        isused3[k-i+n-1] = true;
        queen(k+1);
        board[k][i] = false;
        isused1[i] = false;
        isused2[k+i] = false;
        isused3[k-i+n-1] = false;
    } 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    queen(0);
    cout << cnt;
    return 0;
}