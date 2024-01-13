/*
Naive 한 Union-Find 알고리즘으로 시간초과가 나온 풀이.

쿼리에 따른 시간복잡도가 O(M(M + NlogN)) 이므로 어마어마하게 큰 시간이 걸린다.

# Union By Rank 와 Path Compression 으로 최적화하자.
*/
#include <bits/stdc++.h>
using namespace std;

int parent[1000005];

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
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        make_set(i);
    }
    for (int i = 0; i < m; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            uni(a, b);
        } else {
            cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}