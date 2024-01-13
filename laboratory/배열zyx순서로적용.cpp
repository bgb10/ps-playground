/*
여태까지 배열을 사용할 때 a[x][y] 나 a[z][x][y] 등으로 사용했는데,
이 방식대로 할 경우 cache hit rate 가 떨어진다.
따라서, a[z][y][x] 형식으로 배열을 접근하는 순서를 정하기로 했다.
이전에는 y가 가로, x가 세로였지만, 이제 y가 세로, x가 가로이다.
zyx 순서를 연습해보자.
*/
#include <bits/stdc++.h>
using namespace std;

int d2[4][3];     // y = 4, x = 3 인 행렬
int d3[5][4][3];  // z = 5, y = 4, x = 3 인 행렬

int main() {
    int cnt = 0;

    // 2차원 행렬
    for (int y = 0; y < 4; y++) {      // 세로
        for (int x = 0; x < 3; x++) {  // 가로
            d2[y][x] = ++cnt;
        }
    }

    for (int y = 0; y < 4; y++) {      // 세로
        for (int x = 0; x < 3; x++) {  // 가로
            cout << d2[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cnt = 0;
    // 3차원 행렬

    for (int z = 0; z < 5; z++) {          // 높이
        for (int y = 0; y < 4; y++) {      // 세로
            for (int x = 0; x < 3; x++) {  // 가로
                d3[z][y][x] = ++cnt;
            }
        }
    }

    for (int z = 0; z < 5; z++) {
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 3; x++) {
                cout << d3[z][y][x] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}