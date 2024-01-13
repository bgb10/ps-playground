/*
Topology Sort(위상 정렬) 구현

indegree 가 0인 노드를 우선 방문하고, 방문이 끝났으면 다음 방문할
노드의 indegree 를 감소시킨 다음 0인지 확인해서 반복해서 방문한다.

시간복잡도는 O(V+E) 이다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> di[40000];
int indegree[40000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        di[u].push_back(v);
        indegree[v]++;
    }
    queue<int> Q;
    for (int u = 1; u <= n; u++) {
        if (indegree[u] == 0) Q.push(u);
    }
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for (int nxt : di[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) Q.push(nxt);
        }
    }
    return 0;
}