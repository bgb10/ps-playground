#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[100][100];

void rotate() {
  int tmp[100][100];

  // 1. 임시 저장
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      tmp[i][j] = board[i][j];
    }
  }

  // 2. 회전
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      // 시계방향으로 회전할 것이므로, 배열 오른쪽부터 채워야 하므로 n - 1
      board[j][n - 1 - i] = tmp[i][j]; 
    }
  }

  swap(n, m);
}

void printBoard() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "\n\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> board[i][j];
    }
  }
  cout << "세로 n, 가로 m 인 도형을 0도, 90도, 180도, 270도 회전합니다. \n";
  
  printBoard();
  rotate();
  printBoard();
  rotate();
  printBoard();
  rotate();
  printBoard();

  return 0;
}