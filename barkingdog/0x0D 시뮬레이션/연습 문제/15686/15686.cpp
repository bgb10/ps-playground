#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[51][51];
int dist[51][51];
vector<pair<int, int>> chicken;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int mn = INT_MAX;

void resetDist() {
  for(int x=0; x<n; x++) {
    for(int y=0; y<n; y++) {
      dist[x][y] = -1;
    }
  }
}

/* 
거리를 구할 때, 굳이 집들과의 거리를 일일히 빼줄 필요 없이 BFS 로 탐색하면 됨.
집과 치킨집 사이의 |x차이| + |y차이| 는 곧 BFS 로 탐색할 때의 거리와 같기 때문.
*/ 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      cin >> board[x][y];
      if (board[x][y] == 2)
        chicken.push_back({x, y});
    }
  }
  int ch[14];
  fill(ch, ch + m, 0);
  fill(ch + m, ch + chicken.size(), 1);
  do {
    resetDist();
    queue<pair<int, int>> Q;
    for(int i=0; i<(int)chicken.size(); i++) {
      if(ch[i]) continue;
      Q.push(chicken[i]);
      dist[chicken[i].X][chicken[i].Y] = 0;
    }
    while(!Q.empty()) {
      auto cur = Q.front(); Q.pop();
      for(int i=0; i<4; i++) {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
    // 거리 측정
    int cnt = 0;
    for(int x=0; x<n; x++) {
      for(int y=0; y<n; y++) {
        if(board[x][y] == 1) {
          cnt += dist[x][y];
        }
      }
    }
    // 최소값
    mn = min(cnt, mn);
  } while (next_permutation(ch, ch + chicken.size()));

  cout << mn;
  return 0;
}