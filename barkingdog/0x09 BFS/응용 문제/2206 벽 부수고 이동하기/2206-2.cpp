#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
// 3개 이상의 쌍 부터는 tuple 사용
bool board[SIZE][SIZE];
int dist[SIZE][SIZE][2]; 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
queue<tuple<int, int, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int x=0; x<n; x++)
    for(int y=0; y<m; y++)
    for(int z=0; z<2; z++)
        dist[x][y][z] = -1;
    for(int x=0; x<n; x++) {
        string s;
        cin >> s;
        for(int y=0; y<m; y++) {
            board[x][y] = !(s[y] - '0');
        }
    }
    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int cx = get<0>(cur);
        int cy = get<1>(cur);
        int cz = get<2>(cur);
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!board[nx][ny] && nz == 1) continue;
            // 주의: 여기서 굳이 최소값을 비교할 필요가 없다! 도착한 순간 이미 최소거리다.
            if(dist[nx][ny][nz] != -1 && dist[nx][ny][nz] <= dist[cx][cy][cz] + 1) continue;
            // 벽 뚫는 경우
            if(!board[nx][ny]) 
                nz++;
            dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
            Q.push({nx, ny, nz});
        }
    }
    // 주의: Queue 탐색을 마치고 결과값을 비교하면 아래와 같이 처리가 복잡해진다.
    if(dist[n-1][m-1][0] == -1 && dist[n-1][m-1][1] == -1) {
        cout << -1;
    } 
    else if(dist[n-1][m-1][0] == -1) {
        cout << dist[n-1][m-1][1];
    }
    else if(dist[n-1][m-1][1] == -1) {
        cout << dist[n-1][m-1][0];
    }
    else {
        cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
    return 0;
}