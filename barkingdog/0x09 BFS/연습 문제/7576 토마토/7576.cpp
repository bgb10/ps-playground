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

    for(int x = 0; x < 1002; x++) {
        for(int y = 0; y < 1002; y++) {
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
            } else {
                dist[x][y] = -1;
            }
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        // 이걸 통해 큐 상황을 관찰해서 중복을 해결할 수 있었다.
        // cout << '(' << cur.X << ", " << cur.Y << ") ->";
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == -1) continue;
            int temp_dist = dist[cur.X][cur.Y] + 1;
            // 아래에서 뭔가 중복이 발생하는 것 같은데... 등호 하나 떄문에 큐에 데이터가 너무 많이 쌓여서 메모리 초과 난듯.
            if(dist[nx][ny] != -1) continue; // 방문을 한 적이 있는게 지금 계산한 거리보다 같거나 짧은 경우 skip
            // 먼저 도착하는게 무조건 가까움. BFS 의 특징을 생각해봐.

            dist[nx][ny] = temp_dist;
            Q.push({nx, ny});
        }
    }

    int mx = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(dist[x][y] == -1 && board[x][y] != -1) {
                cout << -1;
                return 0;
            }
            mx = max(mx, dist[x][y]);
        }
    }

    cout << mx;

    return 0;
}