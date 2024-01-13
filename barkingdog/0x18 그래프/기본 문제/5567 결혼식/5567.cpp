/*
간단한 그래프 탐색 문제.

깊이가 1인 노드와 깊이가 2인 노드의 명수를 세면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[503];
bool vis[503];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    int ans = 0;
    vis[1] = 1;
    queue<int> Q;
    // 친구의 명수 세기
    for (int adj : adjs[1]) {
        ans++;
        Q.push(adj);
        vis[adj] = 1;
    }
    // 친구의 친구 명수 세기
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int adj : adjs[cur]) {
            if (vis[adj]) continue;
            vis[adj] = 1;
            ans++;
        }
    }
    cout << ans;
    return 0;
}