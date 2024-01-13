#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[10];
int dist[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist + 10, -1);
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int nxt : adjs[cur]) {
            if (dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    return 0;
}