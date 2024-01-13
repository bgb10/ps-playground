/*
dp를 사용한 풀이

현재 노드의 최소값을 구하기 위해 이전 노드까지의 최소값을 이용한다.
식을 통해 표현하면, dp[i] = 최대값(dp[이전노드들]) + cost[i] 이다.
이때 이전 노드가 없는 노드들은 dp[i] = cost[i] 이고, 이게 곧 초항인데
일반적인 dp 방식으로는 이를 처리하기가 조금 복잡하다.
보통 dp 에서는 bottom-up 방식으로 값을 쌓아나가지만, 이 문제에서는 top-down 방식으로
값을 쌓아나가는 걸로 해결할 수 있다.
재귀함수를 이용해 이전 항들을 호출하고, 이전 항이 계산되어 있다면 이미 계산된 값을 불러오면 된다.
이 방식은 똑같은 dp 이지만, 하향식으로 접근하는 dp라고 생각하면 쉽다.

# 노드 사이의 관계를 표현하는게 까다로울 수 있다. 기존에 있는 자료구조를 이용하기 힘들다면,
직접 정의하는게 빠를 수도 있다.
# 점화식만 찾으면 쉽게 풀 수 있는 문제이다.
*/

#include <bits/stdc++.h>
using namespace std;

int cost[1002];
int dp[1002];
vector<vector<int>> pre;

int solve(int p) {
    // leaf node 인 경우
    if(pre[p].empty()) {
        return dp[p] = cost[p];
    }

    int mx = -1;
    for(int prenode : pre[p]) {
        int pc;
        if(dp[prenode] == -1) {
            pc = solve(prenode);
        }
        else {
            pc = dp[prenode]; // memoization
        }
        mx = max(mx, pc);
    }
    return dp[p] = mx + cost[p];
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        fill(cost, cost+1002, -1);
        pre = vector<vector<int>>(1002); 
        fill(dp, dp+1002, -1);
        int n, k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> cost[i];
        }
        int x, y;
        for(int i=0; i<k; i++) {
            cin >> x >> y;
            pre[y].push_back(x);
        }
        int w;
        cin >> w;
        cout << solve(w) << '\n';
    }
	return 0;
}