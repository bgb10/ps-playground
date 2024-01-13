#include <bits/stdc++.h>

using namespace std;

int n;
int board[12][12];
bool isused[30]; // \ 방향
int tovisitx[30];
int tovisity[30];
int cnt = 0;
int mx = 0;

void solve(int k) {
    if(k == 2*n-1) {
        mx = max(mx, cnt);
        return;
    }
    bool isempty = true;
    // 대각선 시작지점부터 끝 지점까지 탐색 후
    // 비숍을 놓을 수 있는 곳에 놓고 다음 대각선으로 넘어감.
    for(int x = tovisitx[k], y = tovisity[k]; x >= 0 && y < n; x--, y++) {
        if(board[x][y] == 0) continue; // 놓을 수 없는 곳인지 체크
        if(isused[x-y+n-1]) continue; // \ 방향 대각선 체크
        isempty = false;
        isused[x-y+n-1] = true;
        cnt++;
        solve(k+1);
        cnt--;
        isused[x-y+n-1] = false;
    }
    // 만약 대각선 내의 어느 칸에도 비숍을 놓을 수 없을 경우
    // 그냥 바로 다음 대각선으로 넘어감.
    // 한 칸이라도 놓을 수 있을 경우, 굳이 아래 문을 실행할 필요 없다(pruning)
    if(isempty) 
        solve(k+1);
}

int main()
{
    cin >> n;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            cin >> board[x][y];
    // 대각선 별 시작지점 계산
    for(int i=0; i<n; i++) tovisitx[i] = i;
    for(int i=0; i<n-1; i++) tovisitx[i+n] = n-1;
    for(int i=0; i<n-1; i++) tovisity[i] = 0;
    for(int i=0; i<n; i++) tovisity[i+n-1] = i;
    solve(0);
    cout << mx;
    return 0;
}