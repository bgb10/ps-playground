/*
사실 모르는 개념이 들어간 문제였다. 논리의 비약이 있는줄 모르고
계속 붙잡고 있었다. 사실 내가 아는 개념으로는 풀기 힘든 문제.

# 반례를 통해 논리의 비약을 찾아내자.
# 알고리즘에 대한 지식을 넓히자. 지금은 아는 알고리즘이 너무 적다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[200002];
int parent[200002];
bool isdeleted[200002];

void make_set(int x) { parent[x] = x; }

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return find(parent[x]);
    }
}

void uni(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX > rootY) {
        parent[rootY] = rootX;
    } else if (rootX < rootY) {
        parent[rootX] = rootY;
    }
}

int rearrange(int x) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
        uni(u, v);
    }

    return 0;
}