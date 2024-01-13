#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[10][10];
bool visible[10][10];

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int rotateD[4] = {0, 1, 2, 3};
int cctvC = 0;
int cctvRotate[10];
int mn;

void see(int stX, int stY, int dir) {
  int dx = 0, dy = 0;

  if (dir % 4 == UP) {
    dx = -1;
  } else if (dir % 4 == RIGHT) {
    dy = 1;
  } else if (dir % 4 == DOWN) {
    dx = 1;
  } else {
    dy = -1;
  }

  for (int x = stX, y = stY;; x += dx, y += dy) {
    if (x < 0 || x >= n || y < 0 || y >= m)
      break;
    if (board[x][y] == 6)
      break;
    visible[x][y] = 1;
  } 
}   

void solve() {
  int cctvCur = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (board[x][y] != 0 && board[x][y] != 6) {
        if (board[x][y] == 1) {
          see(x, y, RIGHT + cctvRotate[cctvCur]);
        } else if (board[x][y] == 2) {
          see(x, y, LEFT + cctvRotate[cctvCur]);
          see(x, y, RIGHT + cctvRotate[cctvCur]);
        } else if (board[x][y] == 3) {
          see(x, y, UP + cctvRotate[cctvCur]);
          see(x, y, RIGHT + cctvRotate[cctvCur]);
        } else if (board[x][y] == 4) {
          see(x, y, LEFT + cctvRotate[cctvCur]);
          see(x, y, UP + cctvRotate[cctvCur]);
          see(x, y, RIGHT + cctvRotate[cctvCur]);
        } else if (board[x][y] == 5) {
          see(x, y, LEFT + cctvRotate[cctvCur]);
          see(x, y, UP + cctvRotate[cctvCur]);
          see(x, y, RIGHT + cctvRotate[cctvCur]);
          see(x, y, DOWN + cctvRotate[cctvCur]);
        }
        cctvCur++;
      }
    }
  }

  int cnt = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (visible[x][y] == 0 && board[x][y] != 6) {
        cnt++;
      }
    }
  }

  mn = min(mn, cnt);

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      visible[x][y] = 0;
    }
  }

  return;
}

int main() {
  cin >> n >> m;
  mn = n * m; // cctv 가 1개 이상이라는 말이 없어서 INT_MAX 대신 n * m 으로 두는게 안전함.
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      cin >> board[x][y];
      if (board[x][y] != 0 && board[x][y] != 6) {
        cctvC++;
      }
    }
  }
  // 백트래킹 대신 4진법을 사용해 경우의 수를 표현한다.
  // 4진법을 사용한 경우의 수
  // 4 ^ n == 2 ^ 2n
  int k = 1 << 2 * cctvC;
  for (int i = 0; i < k; i++) {
    int tmp = i;
    for (int j = 0; j < cctvC; j++) {
      cctvRotate[j] = tmp % 4;
      tmp /= 4;
    }
    solve();
  }
  cout << mn;
  // 연산량은 (see 함수 호출 개수 * cctv 최대 개수 * see 함수 연산량(배열 체크) + 사각지대 확인) * cctv 경우의 수
  // (4 * 8 * 8 + 64) * 4^8 = 20971520 즉, 다항시간 안에 들어온다.
  // 만약 이렇게 했을 때 다항시간 안에 들어오지 않는 경우, 중복을 제거해주면 된다.
  return 0;
}