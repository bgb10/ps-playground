#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dist[301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<301; i++) fill(dist[i], dist[i] + 301, -1);

    int t;
    cin >> t;
    while(t--) {
        int I;
        int x, y;
        pair<int, int> from;
        pair<int, int> to;
        cin >> I;
        cin >> x >> y;
        from = {x, y};
        cin >> x >> y;
        to = {x, y};

        if(from == to) {
            cout << "0" << '\n';
            continue;
        }
        queue<pair<int, int>> Q;

        dist[from.X][from.Y] = 0;
        Q.push(from);
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int i=0; i<8; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                if(to.X == nx && to.Y == ny) {
                    cout << dist[nx][ny] << '\n';
                }

                Q.push({nx, ny});
            }
        }

        for(int i=0; i<301; i++) fill(dist[i], dist[i] + 301, -1);
    }

    return 0;
}