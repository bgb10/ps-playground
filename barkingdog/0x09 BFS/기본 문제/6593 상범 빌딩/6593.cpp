#include <bits/stdc++.h>
using namespace std;
#define SIZE 32
#define X first
#define Y second

char board[SIZE][SIZE][SIZE];
int dist[SIZE][SIZE][SIZE];

int dx[] = {-1,0,1,0,0,0};
int dy[] = {0,-1,0,1,0,0};
int dz[] = {0,0,0,0,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L, R, C;
    cin >> L >> R >> C;
    tuple<int, int, int> start;
    tuple<int, int, int> end;
    while(!(L==0&&R==0&&C==0)) {
        for(int x=0; x<SIZE; x++)
        for(int y=0; y<SIZE; y++)
        for(int z=0; z<SIZE; z++)
            dist[x][y][z] = -1;
        queue<tuple<int, int, int>> Q;
        for(int z = 0; z < L; z++) {
            for(int x = 0; x < R; x++) {
                for(int y = 0; y < C; y++) {
                    cin >> board[x][y][z];
                    if(board[x][y][z] == 'S') {
                        start = {x, y, z};
                        dist[x][y][z] = 0;
                        Q.push(start);
                    }
                    if(board[x][y][z] == 'E') 
                        end = {x,y,z};
                }
            }
        }
        if(start == end) {
            cout << "Escaped in 0 minute(s)." << "\n";
            cin >> L >> R >> C;
            continue;
        }

        bool istrapped = true;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int cx = get<0>(cur);
            int cy = get<1>(cur);
            int cz = get<2>(cur);
            for(int i=0; i<6; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                int nz = cz + dz[i];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
                if(dist[nx][ny][nz] != -1) continue;
                if(board[nx][ny][nz] == '#') continue;
                if(board[nx][ny][nz] == 'E') {
                    cout << "Escaped in " << dist[cx][cy][cz] + 1 << " minute(s)." << "\n";
                    istrapped = false;
                    break;
                }
                dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
                Q.push({nx, ny, nz});
            }
            if(!istrapped) break;
        }

        if(istrapped) cout << "Trapped!" << "\n";

        cin >> L >> R >> C;
    }
    return 0;
}