#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 수빈이와 동생이 모두 움직일 수 있으면 BFS 와 함께 백트랙킹을 같이 써야했겠지?
// 그게 아니고 수빈이만 움직이고, 최단 거리를 찾는 거니까 BFS 를 쓰면 되는거고.


//segfault: 배열 범위 초과 접근시
bool vis[100004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q; // 값, 시도 횟수

    int n, k;
    cin >> n >> k;

    if(n >= k) {
        cout << n-k;
        return 0;
    }

    Q.push({n, 0});
    vis[n] = 1;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        // 와... 여기서 -1 +1 -1 +1 계속 돌수가 있구나. 방문 체크를 안했으니까...
        if(cur.X + 1 == k) {
            cout << cur.Y + 1;
            return 0;
        }

        if(cur.X - 1 == k) { 
            cout << cur.Y + 1;
            return 0;
        }

        if(cur.X * 2 == k) {
            cout << cur.Y + 1;
            return 0;
        }

        if(cur.X + 1 <= 100000 && !vis[cur.X + 1]) {
            Q.push({cur.X + 1, cur.Y + 1});
            vis[cur.X + 1] = true;
        }
        if(cur.X - 1 >= 0 && !vis[cur.X - 1]) {
            Q.push({cur.X - 1, cur.Y + 1});
            vis[cur.X - 1] = true;
        }
        if(cur.X * 2 <= 100000 && !vis[cur.X * 2]) {
            Q.push({cur.X * 2, cur.Y + 1});
            vis[cur.X * 2] = true;
        }
    }

    return 0;
}