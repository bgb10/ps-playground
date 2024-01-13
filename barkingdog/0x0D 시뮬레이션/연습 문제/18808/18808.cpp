#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int sn, sm;

bool notebook[42][42];
bool sticker[42][42][102];
int stickerSizeX[102];
int stickerSizeY[102];

bool isputtable(int x, int y, int si) {
  for (int i = 0; i < stickerSizeX[si]; i++) {
    for (int j = 0; j < stickerSizeY[si]; j++) {
      if (sticker[i][j][si] == 1 && notebook[x + i][y + j] == 1)
        return false;
    }
  }

  return true;
}

void put(int x, int y, int si) {
  for (int i = 0; i < stickerSizeX[si]; i++) {
    for (int j = 0; j < stickerSizeY[si]; j++) {
      if (sticker[i][j][si] == 1)
        notebook[x + i][y + j] = 1;
    }
  }
}

void rotate(int i) {
  int tmp[42][42];
  for (int x = 0; x < stickerSizeX[i]; x++) {
    for (int y = 0; y < stickerSizeY[i]; y++) {
      tmp[x][y] = sticker[x][y][i];
    }
  }

  for (int x = 0; x < stickerSizeX[i]; x++) {
    for (int y = 0; y < stickerSizeY[i]; y++) {
      sticker[y][stickerSizeX[i] - 1 - x][i] = tmp[x][y];
    }
  }

  swap(stickerSizeX[i], stickerSizeY[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;

  for (int i = 0; i < k; i++) {
    cin >> stickerSizeX[i] >> stickerSizeY[i];
    for (int x = 0; x < stickerSizeX[i]; x++) {
      for (int y = 0; y < stickerSizeY[i]; y++) {
        cin >> sticker[x][y][i];
      }
    }
  }
  for (int i = 0; i < k; i++) {
    bool alreadyPut = false;
    for (int r = 0; r < 4; r++) {
      for (int x = 0; x <= n - stickerSizeX[i]; x++) {
        for (int y = 0; y <= m - stickerSizeY[i]; y++) {
          if (!isputtable(x, y, i))
            continue;
          put(x, y, i);
          alreadyPut = true;
          break;
        }
        if(alreadyPut) 
        // flag 가 true 가 되면 for문 두 개를 모두 빠져나와야 하는데, 바로 인접한 하나의 for문만 빠져나와서
        // 여러번 돌다가 잘못된 결과가 나왔다. 다음에 주의하도록!
          break;
      }
      if (alreadyPut)
        break;
      rotate(i);
    }
  }

  int cnt = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if(notebook[x][y] == 1) cnt++;
    }
  }

  cout << cnt;

  return 0;
}