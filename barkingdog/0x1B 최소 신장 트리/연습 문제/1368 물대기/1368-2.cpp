/*
최소 스패닝 트리를 구하기 위해 문제에서 주어진 그래프를 변형해야 하는 문제.

문제를 읽어보면 최소 스패닝 트리 문제 같지만 우물을 파는 경우 때문에 막상 적용하기 힘들다.
이를 위해 그래프를 변형할 수 있는데, 우물을 파는 경우의 노드를 따로 두면 된다.
우물 역할을 하는 노드를 하나 두고, 다른 노드(논)과의 간선을 두고 우물을 파는 비용을 가중치로 두면 된다.

# 주어진 그래프가 특정한 알고리즘을 적용할 수 있지만 어딘가 애매한 부분이 있을 때, '그래프를 변형'할 수 있다.
해당 문제에서는 우물 역할을 하는 노드를 만들어서 MST를 구했다.
BFS 문제 중에서 1600, 14442 번 문제를 보면, 벽을 부수는 경우나 말을 뛰어넘는 경우가 나는 경우 
일반적인 2차원 그래프로는 해결이 불가능하다. 
이 경우에도 주어진 그래프를 2차원에서 3차원으로 '변형'하여 문제를 해결할 수 있다. (바킹독님 강의 참고)
# 직접 그려보면서 어떻게 그래프를 변형할 수 있을지 고민해보자. 
# 그래프를 변형하는 유형은 정말 자주 나오는 유형이다. 어떤 문제에 그래프를 적용할 수 있을 것 같은데 걸리는 부분이 있다면,
그래프를 변형하여 그 부분을 어떻게 해결할 수 있을지 고민해보자.

*/
#include <bits/stdc++.h>
using namespace std;

int dig[303];
int cost[303][303]; // 0번은 우물 노드

int parent[303];

void make_set(int x) {
    parent[x] = x;
}

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void uni(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    make_set(0); // 우물 노드
    for(int i=1; i<=n; i++) {
        make_set(i);
        cin >> dig[i];
        cost[0][i] = dig[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> cost[i][j];
        }
    }
    // Kruskal Algorithm
    vector<tuple<int, int, int>> to_visit; // cost, a, b
    for(int i=0; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            to_visit.push_back({cost[i][j], i, j});
        }
    }
    sort(to_visit.begin(), to_visit.end());
    int cnt = 0;
    int ans = 0;
    for(auto edge : to_visit) {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if(find(a) == find(b)) continue;
        ans += cost;
        cnt++;
        uni(a, b);
        if(cnt == n) break;
    }
    cout << ans;
    return 0;
}