#include <bits/stdc++.h>
using namespace std;

bool board[1005][1005]; // 벽 존재 1 없음 0 -> 통행 가능 1 통행 불가 0
int dist[1005][1005][2]; // 0: 벽 부수지 않았을 때, 1: 벽을 부쉈을 때

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int z=0; z<2; z++) {
        for(int x=0; x<1005; x++) {
            for(int y=0; y<1005; y++) {
                dist[x][y][z] = -1;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    for(int x=1; x<=n; x++) {
        string s;
        cin >> s;
        
        for(int y=1; y<=m; y++) {
            board[x][y] = !(s[y-1] - '0');
        }
    }

    if(n == m && n == 1) {
        cout << 1;
        return 0;
    }

    queue<tuple<int, int, bool>> Q;

    dist[1][1][0] = 1;
    Q.push({1,1,false});
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if(nx == n && ny == m) {
                cout << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                return 0;
            }

            if(dist[nx][ny][get<2>(cur)] != -1) continue;
            
            if(board[nx][ny] == false) {
                if(get<2>(cur)) {
                    continue;
                } else {
                    dist[nx][ny][1] = dist[get<0>(cur)][get<1>(cur)][0] + 1;
                    Q.push({nx, ny, true});
                    continue;
                }
            }

            dist[nx][ny][get<2>(cur)] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nx, ny, get<2>(cur)});
        }
    }

    cout << -1;

    return 0;
}