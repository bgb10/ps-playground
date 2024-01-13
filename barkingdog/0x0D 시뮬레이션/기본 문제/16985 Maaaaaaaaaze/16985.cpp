/*
브루트포스와 BFS, 순열(?) 의 개념을 종합적으로 사용하는 좋은 문제.

블럭을 어떻게 회전할지 알고리즘을 설계하고, 3차원 배열에서의 BFS를 정의하고,
5개의 판 순서를 섞을 때 순열을 사용해서 섞을 수 있다.
각각의 구현은 그렇게 어렵지 않으나, 이것을 한꺼번에 구현하는 것은 숙련도가 필요하다.
*/
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

bool shuffled[6][6][6];
bool block[6][6][6];
int ans = 0x3f3f3f3f;
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void rotate(int k) {
    bool t[6][6];

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            t[i][j] = shuffled[k][i][j];
        }
    }
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            shuffled[k][j][4-i] = t[i][j];
        }
    }
}

void bfs() {
    if (shuffled[0][0][0] == 0 || shuffled[4][4][4] == 0) return;
    int dist[6][6][6];
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dist[k][i][j] = -1;
            }
        }
    }
    dist[0][0][0] = 0;
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int cz, cx, cy;
        tie(cz, cx, cy) = cur;
        for (int i = 0; i < 6; i++) {
            int nz, nx, ny;
            tie(nz, nx, ny) = cur;
            nz += dz[i];
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if (dist[nz][nx][ny] != -1) continue;
            if (shuffled[nz][nx][ny] == 0) continue;
            dist[nz][nx][ny] = dist[cz][cx][cy] + 1;
            Q.push({nz, nx, ny});
        }
    }
    // cout << dist[4][4][4] << '\n';
    if (dist[4][4][4] == -1)
        return;
    else
        ans = min(ans, dist[4][4][4]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> block[k][i][j];
            }
        }
    }
    int seq[5] = {0, 1, 2, 3, 4};
    do {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    shuffled[seq[i]][j][k] = block[i][j][k];
                }
            }
        }
        for (int a = 0; a < 4; a++) {
            rotate(0);
            for (int b = 0; b < 4; b++) {
                rotate(1);
                for (int c = 0; c < 4; c++) {
                    rotate(2);
                    for (int d = 0; d < 4; d++) {
                        rotate(3);
                        for (int e = 0; e < 4; e++) {
                            rotate(4);
                            bfs();
                        }
                    }
                }
            }
        }
    } while (next_permutation(seq, seq + 5));

    if(ans == 0x3f3f3f3f) cout << -1;
    else cout << ans;

    return 0;
}