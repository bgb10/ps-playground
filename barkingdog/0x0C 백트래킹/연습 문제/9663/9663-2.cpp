#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;

bool isused1[20];
bool isused2[20];
bool isused3[30];

void queen(int x) {
    if(x == n) {
        cnt++;
        return;
    }
    for(int y=0; y<n; y++) {
        if(isused1[y] || isused2[x+y] || isused3[x-y+n-1]) continue;
        isused1[y] = 1;
        isused2[x+y] = 1;
        isused3[x-y+n-1] = 1;
        queen(x+1);
        isused1[y] = 0;
        isused2[x+y] = 0;
        isused3[x-y+n-1] = 0;
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