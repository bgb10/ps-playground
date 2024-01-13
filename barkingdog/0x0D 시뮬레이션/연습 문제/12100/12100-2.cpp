#include <bits/stdc++.h>
using namespace std;

int n;
int board1[21][21]; // 원본
int board2[21][21]; // 기울이는 보드
int mx;

void countMax() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      mx = max(mx, board2[x][y]);
    }
  }
}

void rotate() {
  int tmp[21][21];
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      tmp[x][y] = board2[x][y];
    }
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      board2[y][n - 1 - x] = tmp[x][y];
    }
  }
}

void tilt(int dir) {
  while (dir--)
    rotate();
  for (int x = 0; x < n; x++) {
    int tilted[21] = {}; // 0으로 초기화됨.
    int idx = 0;
    for (int y = 0; y < n; y++) {
      if (board2[x][y] == 0)
        continue;
      else if (tilted[idx] == 0)
        tilted[idx] = board2[x][y];
      else if (tilted[idx] == board2[x][y])
        tilted[idx++] *= 2;
      else
        tilted[++idx] = board2[x][y];
    }
    for (int j = 0; j < n; j++)
      board2[x][j] = tilted[j];
  }
}

void backup() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      board2[x][y] = board1[x][y];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      cin >> board1[x][y];
    }
  }
  for (int i = 0; i < 1024; i++) {
    backup();
    int brute = i;
    for (int j = 0; j < 5; j++) {
      int dir = brute % 4;
      brute /= 4;
      tilt(dir);
    }
    countMax();
  }
  cout << mx;
  return 0;
}