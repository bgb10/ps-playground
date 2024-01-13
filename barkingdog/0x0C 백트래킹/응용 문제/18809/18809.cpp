#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, G, R;
int board[53][53];
vector<int> spreadable; // 배양액을 뿌릴 수 있는 땅의 좌표
int toSpreadGRCh[12]; // 초록, 빨강 배양액을 뿌릴 땅의 좌표 경우의 수 체크하기 위한 변수
vector<int> toSpreadGR; // 초록, 빨강 배양액을 뿌릴 땅의 좌표
int toSpreadGREachCh[12]; // 초록, 빨강 각각의 배양액을 뿌릴 땅의 좌표 경우의 수 체크하는 변수
vector<int> toSpreadG;
vector<int> toSpreadR;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int distG[53][53];
int distR[53][53];
int mx = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int x=0; x<N; x++) {
        for(int y=0; y<M; y++) {
            cin >> board[x][y];
            if(board[x][y] == 2) {
                spreadable.push_back(x * M + y); // 여기서 M 대신 5 라는 상수를 넣어서 계속 안됨...
            }
        }
    }
    fill(toSpreadGRCh, toSpreadGRCh + G + R, 0);
    fill(toSpreadGRCh + G + R, toSpreadGRCh + spreadable.size(), 1);
    do {
        for(int i=0; i<spreadable.size(); i++) {
            if(toSpreadGRCh[i] == 1) continue;
            toSpreadGR.push_back(spreadable[i]);
        }
        fill(toSpreadGREachCh, toSpreadGREachCh + G, 0);
        fill(toSpreadGREachCh + G, toSpreadGREachCh + G + R, 1);
        do {
            for(int i=0; i < G + R; i++) {
                if(toSpreadGREachCh[i] == 1) toSpreadR.push_back(toSpreadGR[i]);
                else toSpreadG.push_back(toSpreadGR[i]);
            }

            // BFS
            for(int x=0; x<N; x++)
            for(int y=0; y<M; y++) {
                distG[x][y] = -1;
                distR[x][y] = -1;
            }
            queue<pair<int, int>> GQ;
            queue<pair<int, int>> RQ;
            for(int i : toSpreadG) {
                GQ.push({i / M, i % M});
                distG[i/M][i%M] = 0;
            }
            for(int i : toSpreadR) {
                RQ.push({i / M, i % M});
                distR[i/M][i%M] = 0;
            }

            int distance = 1;
            int cnt = 0;
            while(!GQ.empty() && !RQ.empty()) {
                vector<pair<int, int>> GV;
                vector<pair<int, int>> RV;
                
                while(!GQ.empty()) {
                    auto cur = GQ.front(); GQ.pop();
                    for(int i=0; i<4; i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(distG[nx][ny] != -1) continue; // 이미 방문한 곳
                        if(board[nx][ny] == 0) continue; // 호수
                        distG[nx][ny] = distG[cur.X][cur.Y] + 1;
                        GV.push_back({nx, ny});
                    }
                }

                while(!RQ.empty()) {
                    auto cur = RQ.front(); RQ.pop();
                    for(int i=0; i<4; i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(distR[nx][ny] != -1) continue; // 이미 방문한 곳
                        if(board[nx][ny] == 0) continue; // 호수
                        distR[nx][ny] = distR[cur.X][cur.Y] + 1;
                        RV.push_back({nx, ny});
                    }
                }

                // 될지 모르겠네...
                int curFlower = 0;
                for(auto i : GV) {
                    bool issame = false;
                    for(auto j : RV) {
                        if(i==j) {
                            issame=true;
                            break;
                        }
                    }
                    // distG[i.X][i.Y] = distance;
                    if(issame) {
                        curFlower++;
                    }
                    else {
                        GQ.push(i);
                    }
                }
                for(auto i : RV) {
                    bool issame = false;
                    for(auto j : GV) {
                        if(i==j) {
                            issame=true;
                            break;
                        }
                    }
                    // distR[i.X][i.Y] = distance;
                    if(issame) {
                        curFlower++;
                    }
                    else {
                        RQ.push(i);
                    }
                }

                curFlower /= 2;

                cnt += curFlower;

                distance++;
            }

            // while(!GQ.empty()) {
            //     auto cur = GQ.front(); GQ.pop();
            //     for(int i=0; i<4; i++) {
            //         int nx = cur.X + dx[i];
            //         int ny = cur.Y + dy[i];
            //         if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            //         if(distG[nx][ny] != -1) continue; // 이미 방문한 곳
            //         if(board[nx][ny] == 0) continue; // 호수
            //         distG[nx][ny] = distG[cur.X][cur.Y] + 1;
            //         GQ.push({nx, ny});
            //     }
            // }
            // while(!RQ.empty()) {
            //     auto cur = RQ.front(); RQ.pop();
            //     for(int i=0; i<4; i++) {
            //         int nx = cur.X + dx[i];
            //         int ny = cur.Y + dy[i];
            //         if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            //         if(distR[nx][ny] != -1) continue; // 이미 방문한 곳
            //         if(board[nx][ny] == 0) continue; // 호수
            //         distR[nx][ny] = distR[cur.X][cur.Y] + 1;
            //         RQ.push({nx, ny});
            //     }
            // }
            
            // if(cnt >= 11) {
            //     cout << "distG: " << '\n';
            //     for(int x=0; x<N; x++) {
            //         for(int y=0; y<M; y++) {
            //             cout << distG[x][y] << ' ';
            //         }
            //         cout << '\n';
            //     }
            //     cout << "distR: " << '\n';
            //     for(int x=0; x<N; x++) {
            //         for(int y=0; y<M; y++) {
            //             cout << distR[x][y] << ' ';
            //         }
            //         cout << '\n';
            //     }
            // }

            mx = max(mx, cnt);

            toSpreadG.clear();
            toSpreadR.clear();
        } while(next_permutation(toSpreadGREachCh, toSpreadGREachCh + G + R));
        toSpreadGR.clear();
    } while(next_permutation(toSpreadGRCh, toSpreadGRCh + spreadable.size()));

    cout << mx;

    return 0;
}