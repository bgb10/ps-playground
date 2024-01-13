#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[10002];
map<pair<int, int>, int> weights;
vector<int> dp[10002];
int p[10002];

void findParent(int cur) {
    for (int child : adjs[cur]) {
        if (p[cur] == child) continue;
        p[child] = cur;
        findParent(child);
    }
}

void dfs(int cur) {
    // 리프 노드의 경우
    if (adjs[cur].size() == 1 && cur != 1) {
        dp[cur].push_back(0);
        return;
    }
    for (int child : adjs[cur]) {
        if (p[cur] == child) continue;  // 부모 노드의 경우 건너뛰기
        dfs(child);
        int mx = -1;
        for (int i : dp[child]) {
            mx = max(mx, i + weights.at({cur, child}));
        }
        dp[cur].push_back(mx);
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        adjs[p].push_back(c);
        adjs[c].push_back(p);
        weights.insert({{p, c}, w});
        weights.insert({{c, p}, w});
    }

    // tree dp 진행
    p[1] = 0;
    findParent(1);
    dfs(1);

    // 모든 노드를 순회하며 최대값 구하기
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if(dp[i].size() == 0) continue;
        if(dp[i].size() == 1) {
            mx = max(mx, dp[i][0]);
            continue;
        }
        vector<int> ans;
        for (int j : dp[i]) {
            ans.push_back(j);
            // cout << j << ' ';
        }
        sort(ans.begin(), ans.end(), greater<>());
        mx = max(mx, ans[0] + ans[1]);
        // cout << '\n';
    }
    cout << mx;
    return 0;
}