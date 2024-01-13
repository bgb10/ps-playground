#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[101][101];
bool vis[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 색약 x: 방문 x시 색깔 확인 -> 그 색깔로 탐색
    // 색약 o: 방문 x시 색깔 확인 -> B일시에는 상관 없지만 R이나 G 일시에는 같이 보고 탐색
    // 그냥 자료구조 자체를 바꿔서 모든 G를 R로 치환하는게 더 깔끔하긴 할듯.

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            board[i][j] = s[j];
        }
    }

    // 색약 X
    int no = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            queue<pair<int, int>> Q;

            if(vis[x][y]) continue;
            vis[x][y] = 1;
            char color = board[x][y];
            Q.push({x, y});

            no++;

            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != color) continue;
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }

    // R과 G를 같은 색깔로 바꾸기 및 vis 초기화
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y ++) {
            vis[x][y] = false;
            if(board[x][y] == 'G') board[x][y] = 'R';
        }
    }

    int yes = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            queue<pair<int, int>> Q;

            if(vis[x][y]) continue;
            vis[x][y] = 1;
            char color = board[x][y];
            Q.push({x, y});

            yes++;

            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != color) continue;
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }

    cout << no << ' ' << yes;

    return 0;
}