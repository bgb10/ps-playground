#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
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
    int mx = 0; // max 는 stl 함수랑 겹치기 때문에 mx로 변수명 사용
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(board[x][y] == 0 || vis[x][y]) continue; // 들여쓰기 하는 대신에 탈출 조건을 미리 써서 코드를 간결히 할 수 있다.
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
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; 
                    vis[nx][ny] = 1;
                    s++;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, s); // 대소비교할 필요 없이 stl 함수 사용
        }
    }

    cout << cnt << '\n' << mx;
   
    return 0;
}