/*
각 간선에 대해서 탐색을 하는 것 같이 보이므로 O(V(V+E)) 라고 착각할 수 있는데,
이미 방문한 간선에 대해서는 탐색하지 않기 때문에 O(V+E)이다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[12];
bool vis[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int v = 1; v <= 10; v++) {
        if (vis[v]) continue;
        queue<int> Q;
        Q.push(v);
        vis[v] = true;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (int nxt : adjs[cur]) {
                if (vis[nxt]) continue;
                Q.push(nxt);
                vis[nxt] = 1;
            }
        }
    }
    return 0;
}