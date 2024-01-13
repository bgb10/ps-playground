#include <bits/stdc++.h>
using namespace std;
#define SIZE 105
#define X first
#define Y second
bool board[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<SIZE; i++) fill(board[i], board[i] + SIZE, 1);
    cin >> m >> n >> k;
    for(int i=0; i<k; i++) {
        int bx, by, ux, uy;
        cin >> by >> bx >> uy >> ux;
        for(int x=bx; x<ux; x++)
            for(int y=by; y<uy; y++)
                board[x][y] = 0;
    }
    int cnt = 0;
    vector<int> V;
    for(int x=0; x<m; x++) {
        for(int y=0; y<n; y++) {
            if(board[x][y] == 0 || vis[x][y]) continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[x][y] = 1;
            Q.push({x, y});
            int s = 0;
            s++;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    s++;
                }
            }
            V.push_back(s);
        }
    }
    sort(V.begin(), V.end());
    cout << cnt << '\n';
    for(int s : V)
        cout << s << ' ';
    return 0;
}