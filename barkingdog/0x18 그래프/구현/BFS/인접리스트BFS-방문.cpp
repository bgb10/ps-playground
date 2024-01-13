#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[10];
bool vis[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int nxt : adjs[cur]) {
            if (vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = 1;
        }
    }
    return 0;
}