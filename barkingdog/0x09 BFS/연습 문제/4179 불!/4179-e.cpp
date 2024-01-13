#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int j[1002][1002];
int f[1002][1002];
int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/*
'이전 풀이'는 지훈이의 이동 속도와 불의 확산 속도를 모두 구해서 경계지점에서 비교했다면,
'개선된 풀이'는 불의 확산을 먼저 구해놓고 지훈이를 이동시키면서 불이 더 빠르게 번진 지점은 제외하고 이동했을 때 경계에 도달하는지를 판단한다.
경계에 도달한다면 지훈이는 불보다 더 빨리 도착한 것이고, 이때 구한 거리는 BFS 의 성질로 인해 무조건 최소값이다.
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 데이터를 -1로 할지, 0으로 할지, 1로 할지 잘 정해라.
    // board: 벽 -1, 지나갈 수 있는 공간 0
    // j: 방문 x -1, 방문 o 0 이상
    // h: j와 같음
    queue<pair<int, int>> JQ;
    queue<pair<int, int>> FQ;

    cin >> r >> c;
    for(int x = 0; x < r; x++) {
        for(int y = 0; y < c; y++) {
            j[x][y] = -1;
            f[x][y] = -1;
            
            char block;
            cin >> block;
            if(block == '#') {
                board[x][y] = -1;
            } else if(block == '.') {
                board[x][y] = 0; 
            } else if(block == 'J') {
                j[x][y] = 0;
                JQ.push({x, y});
            } else if(block == 'F') {
                f[x][y] = 0;
                FQ.push({x, y});
            }
        }
    }

    while(!FQ.empty()) {
        pair<int, int> cur = FQ.front(); FQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == -1) continue; 
            if(f[nx][ny] != -1) continue;

            f[nx][ny] = f[cur.X][cur.Y] + 1;
            FQ.push({nx, ny});
        }
    }

    // 모든 거리를 다 구해놓고 90번째 줄처럼 최소값을 찾는 것은 비효율적이다.
    // 애초에 BFS 에서 오름차순으로 거리를 찾기 때문에, 순회하는 동안 조건에 만족하는 값이 곧 최소값이다.
    while(!JQ.empty()) {
        pair<int, int> cur = JQ.front(); JQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 범위가 벗어났다는 것은 탈출에 성공했다는 것을 의미한다. 그리고 이것은 최소값이다.
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << j[cur.X][cur.Y] + 1;
                return 0;
            }
            if(j[nx][ny] >= 0) continue;
            if(board[nx][ny] == -1) continue;
            if(f[nx][ny] != -1 && f[nx][ny] <= j[cur.X][cur.Y] + 1) continue; // 불이 지훈이보다 더 빠르다면 pass
            
            j[nx][ny] = j[cur.X][cur.Y] + 1;

            // 경계만 체크하면 중간에 불을 마주쳤을 때 문제가 생긴다.
            // // 경계 지점인 경우
            // if(nx == 0 || nx == r-1 || ny == 0 || ny == c-1) {
            //     if(j[nx][ny] < f[nx][ny]) {
            //         cout << j[nx][ny] + 1;
            //         return 0;
            //     }
            // }
            
            JQ.push({nx, ny});
        }
    }

    // 이때는 최소값을 찾아야 한다. 빙 돌아야 하니까.
    // int mn = INT_MAX;
    // for(int x=0, y=0; x<r; x++) {
    //     if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
    //         mn = min(mn, j[x][y]);
    //     }
    // }
    // for(int x=0, y=c-1; x<r; x++) {
    //     if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
    //         mn = min(mn, j[x][y]);
    //     }
    // }
    // for(int x=0, y=0; y<c; y++) {
    //     if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
    //         mn = min(mn, j[x][y]);
    //     }
    // }
    // for(int x=r-1, y=0; y<c; y++) {
    //     if((f[x][y] == -1 || j[x][y] < f[x][y]) && j[x][y] != -1 && board[x][y] == 0) {
    //         mn = min(mn, j[x][y]);
    //     }
    // }

    // if(mn == INT_MAX) {
    //     cout << "IMPOSSIBLE";
    // } else {
    //     cout << mn + 1;
    // }

    cout << "IMPOSSIBLE";

    return 0;
}