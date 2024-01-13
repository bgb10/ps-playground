// 0-1 BFS, 불을 먼저 BFS 하고, 지훈이를 다음에 돌리면 됨.

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int r, c;

bool board[1004][1004];
int dist_F[1004][1004];
int dist_J[1004][1004];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

pair<int, int> J;
vector<pair<int, int>> F;

int main() {
  cin >> r >> c;
  string t[1004];
  for(int i=0; i<r; i++) {
    cin >> t[i];
  }

  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      if(t[i][j] == '#') {
        board[i][j] = 0;
      }
      else if(t[i][j] == '.') {
        board[i][j] = 1;
      }
      else if(t[i][j] == 'J') {
        J = {i, j};
        board[i][j] = 1;
      }
      else if(t[i][j] == 'F') {
        F.push_back({i, j});
        board[i][j] = 1;
      } 
    }
  }

  // Fire
  for(int i=0; i<r; i++) fill(dist_F[i], dist_F[i]+c, -1);
  queue<pair<int, int>> Q;
  for(auto k : F) {
    dist_F[k.X][k.Y] = 0;
    Q.push(k);
  }
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for(int i=0; i<4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(board[nx][ny] == 0 || dist_F[nx][ny] != -1) continue;
      dist_F[nx][ny] = dist_F[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }
  
  // Jihoon
  for(int i=0; i<r; i++) fill(dist_J[i], dist_J[i]+c, -1);
  dist_J[J.X][J.Y] = 0;
  Q.push(J);
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for(int i=0; i<4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(board[nx][ny] == 0 || dist_J[nx][ny] != -1) continue;
      if(dist_J[cur.X][cur.Y] + 1 >= dist_F[nx][ny] && dist_F[nx][ny] != -1) continue;
      dist_J[nx][ny] = dist_J[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }

  // check jihoon escaped
  int mn = INT_MAX;

  for(int i=0; i<r; i++) {
    if(board[i][0] != 0 && dist_J[i][0] != -1) mn = min(mn, dist_J[i][0]);
    if(board[i][c-1] != 0 && dist_J[i][c-1] != -1) mn = min(mn, dist_J[i][c-1]);
  }
  for(int i=0; i<c; i++) {
    if(board[0][i] != 0 && dist_J[0][i] != -1) mn = min(mn, dist_J[0][i]);
    if(board[r-1][i] != 0 && dist_J[r-1][i] != -1) mn = min(mn, dist_J[r-1][i]);
  }

  if(mn == INT_MAX) {
    cout << "IMPOSSIBLE";
  }
  else {
    cout << mn + 1;
  }

  return 0;
}