/*
비록 틀렸지만, DP를 잘 적용한 풀이.

전체 문제는 w를 최단시간으로 짓는 것이고, 부분 문제는 i를 최단시간으로 짓는 것이다.
이때 dp[i] = dp[i 이전 노드들] + cost[i] 가 성립하고, 이전 노드가 없는 경우에 dp[leaf] = cost[leaf] 이다.
그 후 항을 채워나가기 위해 dp항에 대해 i를 1부터 하나씩 채워나간다.
따라서 아래의 풀이는 1->2, 2->3 과 같이 이전 노드가 다음 노드보다 작을 때에만 성립한다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bf[1002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int cost[1002];
        fill(bf, bf+1002, vector<int>());
        for(int i=1; i<=n; i++) {
            cin >> cost[i];
        }
        int x, y;
        for(int i=0; i<k; i++) {
            cin >> x >> y;
            bf[y].push_back(x);
        }
        int w;
        cin >> w;
        int dp[1004];
        fill(dp, dp+1004, 0);
        // 이전 노드가 없는 경우 자기자신만 건설하면 됨.
        for(int i=1; i<=n; i++) {
            if(bf[i].empty()) {
                dp[i] = cost[i];
            }
        }
        // 각 노드에 대해
        for(int i=1; i<=n; i++) {
            if(dp[i] != 0) continue; // 이미 거리가 계산된 경우 skip
            vector<int> dps;
            for(int c : bf[i]) {
                dps.push_back(dp[c]);
            }
            dp[i] = *max_element(dps.begin(), dps.end()) + cost[i];
        }
        cout << dp[w] << '\n';
    }
	return 0;
}