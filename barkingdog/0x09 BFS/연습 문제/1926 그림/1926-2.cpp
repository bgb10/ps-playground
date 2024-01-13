#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// board[x][y] 에서 x = 행, y = 열
int board[502][502];
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n, m; // n = 행의 수, m = 열의 수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    cin >> n >> m;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }
    int cnt = 0;
    int mx = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(board[x][y] == 0 || vis[x][y]) continue;
            int s = 0;
            vis[x][y] = 1;
            Q.push({x, y});
            cnt++;
            s++;
            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                    vis[nx][ny] = 1; // (nx, ny) 를 방문했다고 명시 -> 지금 시점이 아닌 큐에서 뽑은 시점에 방문을 명시하게 되면 다른 곳에서 중복 방문할 가능성 존재
                    s++;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, s);
        }
    }
    cout << cnt << '\n' << mx;
    return 0;
}