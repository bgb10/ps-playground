/*
노드의 depth 를 알아야 할 경우 depth 배열을 사용한다.

BFS 1번으로 각 노드의 depth 와 부모 노드 모두 알아낼 수 있다.
시간복잡도 O(V+E) = O(V+V-1) = O(V) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int p[10];
int depth[10]; // 노드의 depth 를 기록하는 배열

void bfs(int root) {
    queue<int> Q;
    Q.push(root);
    depth[root] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            if(p[cur] == nxt) continue;
            Q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}