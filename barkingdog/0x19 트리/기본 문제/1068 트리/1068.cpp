/*
트리 DP를 이용한 풀이.

DP를 이용해 트리의 리프 노드의 누적합을 구하되, 삭제된 노드인 경우
세지 않는다. 이때 삭제된 노드의 부모 노드의 자식 개수가 1개일 경우
부모 노드가 새로운 리프 노드가 됨에 주의하자.

# 주어진 트리가 2개 이상일 수 있음에 주의하자.
# 리프 노드가 새로 만들어질 수 있음에 주의하자.
# 주어진 예시 말고도 많은 edge case 들을 찾아야 한다.
# 노드를 제거하는 처리에 꽤 다양한 방법이 존재할 듯 하다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[52];
int par[52];
int dp[52];
int erased;

int dfs_dp(int cur) {
    if (cur == erased) {
        return 0;
    }
    if (adjs[cur].empty()) {
        return dp[cur] = 1;
    }
    int leaf_cnt = 0;
    for (int nxt : adjs[cur]) {
        if(par[cur] == nxt) continue;
        int nxt_dp = dfs_dp(nxt);
        leaf_cnt += nxt_dp;
        // 노드를 지움으로서 새로운 리프노드가 생기는 경우
        if(nxt_dp == 0 && adjs[cur].size() == 1) {
            leaf_cnt++;
        }
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
        if(v != -1) adjs[v].push_back(u);
    }
    cin >> erased;
    int ans = 0;
    for (int u = 0; u < n; u++) {
        if (par[u] != -1) continue;
        ans += dfs_dp(u);
    }
    cout << ans;
    return 0;
}