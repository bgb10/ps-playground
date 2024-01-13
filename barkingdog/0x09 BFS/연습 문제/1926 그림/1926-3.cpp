#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[503][503];
bool vis[503][503];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> board[i][j];
    }
  }

  int cnt = 0, mx = 0;
  for(int x=0; x<n; x++) {
    for(int y=0; y<m; y++) {
      if(board[x][y] == 0 || vis[x][y]) continue;
      cnt++;
      vis[x][y] = 1;
      queue<pair<int, int>> Q;
      Q.push({x, y});
      int s = 0;
      while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        s++;
        for(int i=0; i<4; i++) {
          int nx = cur.first + dx[i];
          int ny = cur.second + dy[i];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      mx = max(mx, s);
    }
  }

  cout << cnt << '\n' << mx;

  return 0;
}