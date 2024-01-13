/*
Tree DP 문제이다. DFS와 DP를 사용해서 풀 수 있다.

Tree 에서 DFS 를 돌면서 depth 가 가장 높은 노드부터 노드의 개수를 누적해서 올라가면 된다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[100002];
bool vis[100002];
int cnt[100002];

int dfs(int cur) {
    vis[cur] = 1;
    int sum = 1;
    for (int nxt : adjs[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        sum += dfs(nxt);
    }
    return cnt[cur] = sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, q;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    cnt[r] = dfs(r);
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << cnt[u] << '\n';
    }
    return 0;
}