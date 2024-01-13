#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool mask[25];
string board[5];
bool vis[5][5];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<5; i++)
        cin >> board[i];
    fill(mask + 7, mask + 25, true);
    do {
        // 인접 여부 확인 (공주들이 이웃해있지 않은 상황 판단)
        int prince = 0;
        int dasom = 0;
        for(int x=0; x<5; x++) {
            for(int y=0; y<5; y++) {
                if(mask[x * 5 + y] || vis[x][y]) continue;
                prince++;
                queue<pair<int, int>> Q;
                vis[x][y] = 1;
                Q.push({x, y});
                if(board[x][y] == 'S') dasom++;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int i=0; i<4; i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                        if(mask[nx * 5 + ny] || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        if(board[nx][ny] == 'S') dasom++;
                    }
                }
            }
        }
        // 칠공주 조건 확인
        if(prince == 1 && dasom >= 4) ans++;

        for(int i=0; i<5; i++) fill(vis[i], vis[i]+5, 0);
    } while(next_permutation(mask, mask + 25));
    
    cout << ans;
    
    return 0;
}