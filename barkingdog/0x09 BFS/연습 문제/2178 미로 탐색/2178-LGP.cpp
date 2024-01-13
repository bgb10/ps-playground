// 0-1 BFS

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

string board[103];
int dist[103][103];

int main() {
  int n, m;
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    cin >> board[i];
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> Q;
  dist[0][0] = 0;
  Q.push({0, 0});
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for(int i=0; i<4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '0' || dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }

  cout << dist[n-1][m-1] + 1;

  return 0;
}