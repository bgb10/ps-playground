/*
Union-Find 알고리즘을 구현하는 단순한 문제.

Path Compression 으로 시간복잡도를 줄였다.

시간복잡도는 O(MlogN) 이다.

# Path Compression 만 해도 로그 시간복잡도로 줄기 때문에 굳이 Rank By Union 을 할 필요가 없다.
*/
#include <bits/stdc++.h>
using namespace std;

int parent[1000005];

void make_set(int x) { parent[x] = x; }

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
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