/*
MST를 구하면 되는 쉬운 문제.

'모든 행성 간에 플로우를 설치' 해야 하고 (연결 그래프), 
'제국의 모든 행성을 연결하면서 플로우 관리 비용을 최소한으로 해야 한다.' (모든 노드를 연결하는 최소 비용) 는 것을 보아,
주어진 상황을 그래프로 추상화하고 MST를 구하면 된다.

Kruskal 알고리즘을 사용하였다.

# 시간복잡도는 O(N^2logN) 이다. (그래프의 간선 N(N-1)/2 에 대해 Union-Find logN 수행)
# find 하고 union 돌리는걸 까먹어버렸다 헤헤...
*/
#include <bits/stdc++.h>
using namespace std;

int adjs[1005][1005];
int parent[1005];

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
    for(int i=0; i<n; i++) {
        make_set(i);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> adjs[i][j];
        }
    }
    vector<tuple<int, int, int>> to_visit;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            to_visit.push_back({adjs[i][j], i, j});
        }
    }
    sort(to_visit.begin(), to_visit.end());
    int cnt = 0;
    long long ans = 0;
    for(auto edge : to_visit) {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if(find(a) == find(b)) continue;
        uni(a, b);
        cnt++;
        ans += cost;
        if(cnt == n-1) break;
    }
    cout << ans;
    return 0;
}