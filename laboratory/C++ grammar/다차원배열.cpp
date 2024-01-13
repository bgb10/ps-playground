#include <bits/stdc++.h>
using namespace std;
#define X 2
#define Y 3
#define Z 4

int second[X][Y];   // 2차원배열
int third[X][Y][Z]; // 3차원배열
// n 차원 배열은 선언과 접근 순서는 모두 동일하다.
// 하지만 원하는 구현에 따라 for문 순서는 달라질 수 있다.

// 도형의 특성과 cache hit rate 를 고려한다면 아래와 같이 배열을 작성해야 한다.
// arr[y][x] 는 길이 x 짜리 배열을 y개 담은 배열이 존재하는 것으로 해석한다.
// arr[z][y][x] 는 길이 x짜리 배열을 y개 담은 배열을 z개 담은 배열이 존재하는 것으로 해석한다.
// 하지만 나의 편의를 위해 아래 예제와 같이 작성한다. 그리고 성능상으로는 큰 차이가 없다.

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << "2차원 배열\n";
  int cnt = 0;
  for (int x = 0; x < X; x++) {
    for (int y = 0; y < Y; y++) {
      second[x][y] = cnt++;
    }
  }

  for (int x = 0; x < X; x++) {
    for (int y = 0; y < Y; y++) {
      cout << second[x][y] << ' ';
    }
    cout << '\n';
  }

  cout << "\n\n";
  cout << "3차원 배열\n";

  cnt = 0;
  for (int z = 0; z < Z; z++) {
    for (int x = 0; x < X; x++) {
      for (int y = 0; y < Y; y++) {
        third[x][y][z] = cnt++;
      }
    }
  }

  for (int z = 0; z < Z; z++) {
    for (int x = 0; x < X; x++) {
      for (int y = 0; y < Y; y++) {
        cout << third[x][y][z] << ' ';
      }
      cout << '\n';
    }
    cout << "\n";
  }

  return 0;
}