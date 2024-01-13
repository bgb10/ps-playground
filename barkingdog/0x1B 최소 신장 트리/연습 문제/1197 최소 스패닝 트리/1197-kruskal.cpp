/*
Kruskal Algorithm 구현

각 간선 E에 대해 유니온 파인드 연산을 하므로
시간복잡도는 O(ElogE) 이다.

# Naive 하게 유니온 파인드시 시간복잡도가 매우 크므로, Union Rank 와 Path Compression 은 꼭 해주자.
*/
#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> p(10005, -1);
vector<int> rrank(10005, 0);
tuple<int, int, int> edge[100005];

int find(int x) {
    if(p[x] == -1) return x;
    else return p[x] = find(p[x]);
}

bool is_diff_group(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if(rootX == rootY) return false;
    else {
        if(rrank[rootX] > rrank[rootY]) {
            p[rootY] = rootX;
        }
        else if(rrank[rootX] < rrank[rootY]) {
            p[rootX] = rootY;
        }
        else {
            p[rootY] = rootX;
            rrank[rootX]++;
        }
        return true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge+e);
    int cnt = 0;
    int ans = 0;
    for(int i=0; i<e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
    return 0;
}