#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];
int dist[101][101][101];

int dx[6] = {-1, 0,  0, 1, 0, 0};
int dy[6] = {0, -1,  0, 0, 1, 0};
int dz[6] = {0,  0, -1, 0, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h;
    cin >> m >> n >> h;

    // 방문 여부를 결정하는게 아니라 거리를 결정하는 거면, 
    // 모든 시작점을 큐에 넣어놔야 최단 거리를 구할 수 있다.

    queue<tuple<int, int, int>> Q;

    for(int z = 0; z < h; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                cin >> board[z][x][y];
                if(board[z][x][y] == 1) {
                    dist[z][x][y] == 0;
                    Q.push({x,y,z});
                } else {
                    dist[z][x][y] = -1;
                }
            }
        }
    }

    for(int z = 0; z < h; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int i=0; i<6; i++) {
                        int nx = get<0>(cur) + dx[i];
                        int ny = get<1>(cur) + dy[i];
                        int nz = get<2>(cur) + dz[i];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
                        if(dist[nz][nx][ny] != -1) continue;
                        if(board[nz][nx][ny] == -1) continue;
                        dist[nz][nx][ny] = dist[get<2>(cur)][get<0>(cur)][get<1>(cur)] + 1;
                        Q.push({nx, ny, nz});
                    }
                }
            }
        }
    }

    int mx = -1;
    for(int z = 0; z < h; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                if(board[z][x][y] != -1 && dist[z][x][y] == -1) {
                    cout << "-1";
                    return 0;
                }
                mx = max(mx, dist[z][x][y]);
            }
        }
    }

    cout << mx;

    return 0;
}