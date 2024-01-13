#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
vector<int> V;
string board[26];
bool vis[26][26];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> board[i];
    int ans = 0;
    int cnt = 0;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            if(board[x][y] == '0' || vis[x][y]) continue;
            ans++;
            queue<pair<int, int>> Q;
            vis[x][y] = 1;
            Q.push({x, y});
            cnt++;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == '0' || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    cnt++;
                }
            }
            V.push_back(cnt);
            cnt = 0;
        }
    }
    sort(V.begin(), V.end());
    cout << ans << '\n';
    for(int i : V)
        cout << i << '\n';
    return 0;
}