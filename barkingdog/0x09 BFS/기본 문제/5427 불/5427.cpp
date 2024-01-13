#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

bool board[1005][1005];
int s[1005][1005];
int f[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int w, h;
        cin >> w >> h;
        
        for(int i=0; i<1005; i++) {
            fill(board[i], board[i] + 1005, false);
            fill(s[i], s[i] + 1005, -1);
            fill(f[i], f[i] + 1005, -1);
        }

        queue<pair<int, int>> SQ;
        queue<pair<int, int>> FQ;

        for(int x = 0; x < h; x++) {
            for(int y = 0; y < w; y++) {
                char block;
                cin >> block;
                if(block != '#') board[x][y] = true; // 통행 o true, 통행 x false
                if(block == '@') {
                    s[x][y] = 0;
                    SQ.push({x, y});
                } else if(block == '*') {
                    f[x][y] = 0;
                    FQ.push({x, y});
                }
            }
        }

        while(!FQ.empty()) {
            auto cur = FQ.front(); FQ.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] == false || f[nx][ny] != -1) continue;
                f[nx][ny] = f[cur.X][cur.Y] + 1;
                FQ.push({nx, ny});
            }
        }

        bool escaped = false;
        while(!SQ.empty()) {
            auto cur = SQ.front(); SQ.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cout << s[cur.X][cur.Y] + 1 << '\n';
                    escaped = true;
                    SQ = queue<pair<int, int>>(); // 큐 클리어해서 loop 빠져나가기 위함.
                    break;
                }
                if(board[nx][ny] == false || s[nx][ny] != -1) continue;
                //불이 번진 곳에 대해 불이 상근이보다 더 빨리 번졌을 때 체크. 불이 안번진 곳이면 무조건 움직일 수 있다.
                // 주의!!: 불이 퍼지지 못하는 곳이라면 -1일 것이다. 
                // 불의 거리가 -1인 경우 상근이보다 빨리 이동한게 아니다.
                if(f[nx][ny] != -1 && s[cur.X][cur.Y] + 1 >= f[nx][ny]) continue; 
                s[nx][ny] = s[cur.X][cur.Y] + 1;
                SQ.push({nx, ny});
            }
        }

        if(!escaped) cout << "IMPOSSIBLE" << '\n';

        FQ = queue<pair<int, int>>();
        SQ = queue<pair<int, int>>();
    }

    return 0;
}