#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int board[101][101];
bool vis[101][101];

int dist[101][101];
int who_vis[101][101];
queue<tuple<int, int, int>> border;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            cin >> board[x][y];
    int cnt = 0;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            if(board[x][y] == 0 || vis[x][y]) continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[x][y] = true;
            board[x][y] = cnt;
            Q.push({x, y});
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                bool is_border = false;
                for(int i=0; i<4; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] == 0) {
                        is_border = true;
                        continue;
                    }
                    vis[nx][ny] = true;
                    board[nx][ny] = cnt;
                    Q.push({nx, ny});
                }
                if(is_border) {
                    border.push({cur.X, cur.Y, cnt});
                    who_vis[cur.X][cur.Y] = cnt;
                    dist[cur.X][cur.Y] = 0;
                }
            }
        }
    }

    // 최소값이라고 해서 탐색을 그냥 끝내게 되면, 1 1 로 마주보는 경우랑 1 0 1 로 마주보는 경우랑 구별이 안된다.
    // 1 0 1 양쪽의 것이 queue 에 먼저 들어가 있다면, 먼저 마주치기 때문.
    // 그렇게 하면 안되고, 같은 거리에 있는 애들끼리는 BFS를 일단 다 돌아봐야 하는것임.
    // 나아가, 그냥 모든 거리를 탐색하고 나서 최소값을 구하는게 가장 안전.
    // (틀리는데에는 다 이유가 있구나... 이런 경계값들이 정말 무섭다.)
    int mn = INT_MAX;
    while(!border.empty()) {
        auto cur = border.front(); border.pop();
        for(int i=0; i<4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(who_vis[nx][ny] != 0 && who_vis[nx][ny] != get<2>(cur)) {
                // 두 다리가 만난 경우, 거리 기록
                mn = min(mn, dist[nx][ny] + dist[get<0>(cur)][get<1>(cur)]);
                continue;
            }
            if(who_vis[nx][ny] == get<2>(cur)) continue;
            if(board[nx][ny] != 0) continue;
            who_vis[nx][ny] = get<2>(cur);
            dist[nx][ny] = dist[get<0>(cur)][get<1>(cur)] + 1;
            border.push({nx, ny, get<2>(cur)});
        }
    }

    cout << mn;

    return 0;
}