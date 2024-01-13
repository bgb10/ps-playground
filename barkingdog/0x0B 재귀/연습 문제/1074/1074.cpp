#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

// 재귀 너무 많이 돌리면 시간초과 난다...

int cnt = 0;

int n, r, c;

void z(pair<int, int> start, int n) {
    int cx = start.X;
    int cy = start.Y;
    if(n == 2) {
        pair<int, int> v1 = {cx, cy};
        pair<int, int> v2 = {cx, cy + 1};
        pair<int, int> v3 = {cx + 1, cy};
        pair<int, int> v4 = {cx + 1, cy + 1};
        for(pair<int, int> cur : {v1, v2, v3, v4}) {
            if(cur == make_pair(r, c)) {
                cout << cnt;
                exit(0);
            } else {
                cnt++;
            }
        }
    } else {
        int delta = n / 2;
        if(r < cx + delta && c < cy + delta) {
            z({cx, cy}, delta);
        }
        else if(r < cx + delta && c >= cy + delta) {
            cnt += delta * delta; 
            z({cx, cy + delta}, delta);
        }
        else if(r >= cx + delta && c < cy + delta) {
            cnt += delta * delta * 2;
            z({cx + delta, cy}, delta);
        }
        else {
            cnt += delta * delta * 3;
            z({cx + delta, cy + delta}, delta);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;

    cin >> n >> r >> c;    

    z({0,0},pow(2, n));

    return 0;
}