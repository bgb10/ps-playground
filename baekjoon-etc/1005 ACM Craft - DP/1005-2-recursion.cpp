/*
순차적인 노드의 연결이 있을 때만 풀 수 있는걸 해결하기 위해 재귀를 도입했다.

pre 로 각 노드의 이전 노드를 저장하고, 이전 노드를 추적해서 답을 구할 수 있다.
이때 식은 f(p) = 최대값(f(p 이전 노드들)) + cost[p] 이다.
하지만 dp 적용 없이 위의 방식대로 할 경우, 계산 중복이 굉장히 많이 발생할 수 있다.
예를 들어, n1->n2, n1->n3, n1->n4 로 이어져있다고 하자. 이때 w 가 n2, n3, n4 와 모두 이어져 있다면,
n2, n3, n4 를 계산해야 하는데, 이때 n1 에 대해 3번이나 중복 계산이 발생한다. 

위의 중복을 해결하기 위해 dp 에서 쓰는 memoization 을 사용한다.
*/

#include <bits/stdc++.h>
using namespace std;

int cost[1002];
vector<int> pre[1002];

int solve(int p) {
    if(pre[p].empty()) {
        return cost[p];
    }

    vector<int> pc;
    for(int i : pre[p]) {
        pc.push_back(solve(i));
    }
    return *max_element(pc.begin(), pc.end()) + cost[p];
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> cost[i];
        }
        for(int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            pre[y].push_back(x);
        }
        int w;
        cin >> w;
        cout << solve(w) << '\n';
        fill(cost, cost+n, 0);
        fill(pre, pre+n, vector<int>());
    }
	return 0;
}