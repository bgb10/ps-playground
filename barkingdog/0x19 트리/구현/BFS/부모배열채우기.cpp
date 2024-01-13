/*
부모 노드의 정보가 필요할 경우 부모 노드를 기록하는 배열을 사용한다.

시간복잡도 O(V+E) = O(V + V-1) = O(V) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int p[10];  // 부모 노드를 기록하는 배열

void bfs(int root) {
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;  // 부모 노드를 방문하는 경우
            Q.push(nxt);
            p[nxt] = cur;  // 자식 노드의 부모 노드를 현재 노드로 표시
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}