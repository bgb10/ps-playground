#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000003

int vis[SIZE];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(vis, vis+SIZE, -1);
    int f, g, s, u, d; // floor, goal, start, up, down
    cin >> f >> s >> g >> u >> d;
    if(s == g) {
        cout << 0;
        return 0;
    }
    queue<int> Q;
    vis[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur + u, cur - d}) {
            if(nxt < 1 || nxt > f) continue;
            if(vis[nxt] != -1) continue;
            if(nxt == g) {
                cout << vis[cur] + 1;
                return 0;
            }
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << "use the stairs";
    return 0;
}