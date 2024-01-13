#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
int dist[502][502]; // 거리는 dist 로 
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
        string s;
        cin >> s;
        for(int y = 0; y < m; y++) {
            board[x][y] = s[y] - '0';
        }
    }

    // 아래 처럼 문제에 주어진 조건대로 시작지점의 거리를 0으로 하기 위해
    // 방문되지 않은 모든 지점을 -1 로 채우는 것이 좋겠다.
    // 그렇게 하면 방문한 지점과 방문하지 않은 지점을 쉽게 구별할 수 있다.
    dist[0][0] = 0;
    for(int i=0; i<n; i++) fill(dist[i], dist[i]+m, -1);

    Q.push({0, 0});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        // cout << '(' << cur.X << ", " << cur.Y << ") ->"; 이렇게 방문 지점을 살펴보는 출력문을 두는 것도 디버깅할 때 나쁘지 않은듯.
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1] + 1;

    return 0;
}