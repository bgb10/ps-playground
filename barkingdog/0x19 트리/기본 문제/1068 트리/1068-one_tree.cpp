/*
트리 DP를 이용한 풀이.

DP를 사용해 리프 노드의 누적합을 구한 다음, 루트의 누적합과 지우려는 노드의
누적합을 빼면 된다. 이때 지우려는 노드의 부모 노드가 자식이 하나일 경우, 부모
노드가 새로운 리프 노드가 됨을 고려해야 한다.

# 이 풀이는 트리가 1개만 주어졌을 때 유효하다. 하지만 문제에서는 별도의 얘기가
없으므로 트리가 여러개일 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[52];
int par[52];
int dp[52];

int dfs_dp(int cur) {
    if (adjs[cur].empty()) {
        return dp[cur] = 1;
    }
    int leaf_cnt = 0;
    for (int nxt : adjs[cur]) {
        leaf_cnt += dfs_dp(nxt);
    }
    return dp[cur] = leaf_cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int u = 0; u < n; u++) {
        int v;
        cin >> v;
        par[u] = v;
        if (u == 0) continue;
        adjs[v].push_back(u);
    }
    dfs_dp(0);
    int to_erase;
    cin >> to_erase;
    int ans = dp[0] - dp[to_erase];
    // 루트를 지울 경우 리프 노드는 없다.
    if (par[to_erase] == -1) cout << 0;
    // 지우는 노드의 부모의 자식이 하나밖에 없었던 경우 부모 노드가 리프가 된다.
    else if (adjs[par[to_erase]].size() == 1)
        cout << ans + 1;
    else
        cout << ans;

    return 0;
}