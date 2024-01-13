#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 데이터를 -1로 할지, 0으로 할지, 1로 할지 잘 정해라.
    // board: 벽 -1, 방문 x 0, 방문 o 1
    // dist: 방문 x -1, 벽 0, 방문 o 0 이상
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            board[x][y] = -1;
        }
    }

    // queue<pair<int, int>> SQ; // 굳이 별도의 큐를 둘 필요가 없었지....... 특히 이걸 한 번 더 감싸서 loop 를 돌리면 n^3 이 된다.
    queue<pair<int, int>> Q;

    cin >> m >> n;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            cin >> board[x][y];
            if(board[x][y] == 1) {
                Q.push({x, y});
                dist[x][y] = 0;
            }
            if(board[x][y] == 0) {
                dist[x][y] = -1;
            }
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        // cout << '(' << cur.X << ", " << cur.Y << ") ->"; 이걸 통해 큐 상황을 관찰해서 중복을 해결할 수 있었다.
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == -1) continue;
            // int temp_dist = dist[cur.X][cur.Y] + 1;
            // 아래에서 뭔가 중복이 발생하는 것 같은데... '등호 하나' 를 놓쳐서 큐에 중복된 데이터가 마구 들어간듯. 거리가 같을 때도 계산할 필요는 없잖아.
            // if(dist[nx][ny] != -1 && dist[nx][ny] <= temp_dist) continue; // 방문을 한 적이 있는게 지금 계산한 거리보다 같거나 짧은 경우 skip
            
            // 위에서 처럼 거리를 계산할 필요가 없다. BFS 는 한 번 거리가 기록되면, 그게 최소 거리다.
            // 트리를 생각해 봤을 때, 트리의 깊이가 곧 거리를 의미하는데, BFS 는 깊이가 같은 노드를 기준으로 먼저 탐색하기 때문이다.
            if(dist[nx][ny] != -1) continue; // 이미 방문한 경우 skip

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int mx = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(dist[x][y] == -1) { // 방문하지 않은 곳이 있다면
                cout << -1;
                return 0;
            }
            mx = max(mx, dist[x][y]);
        }
    }

    cout << mx;

    return 0;
}