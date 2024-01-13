/*
그리디한 풀이를 위해 union-find 자료구조를 사용할 수 있다.

비행기의 gi 에 가장 가까운 게이트에 도킹해야 하는데(그리디), 어느 게이트가 비어있는지를
아는 것은 순차적으로 탐색할 경우 O(N)이 걸린다.
이를 위해 union-find 자료구조를 사용할 수 있다.
각 집합의 root 들이 자신, 또는 자신의 root보다 1 아래의 게이트를 가리키도록 한다(즉, 자신의 root-1과 union).
자신을 가리킬 때는 해당 게이트를 사용할 수 있는 경우이며,
자신보다 1 아래를 가리킬 경우에는 다른 게이트를 사용해야 함을 의미한다.
이를 이용해서 게이트를 배정할 수 있고, 더이상 게이트가 없을 경우 root 가 0 이 되어서 폐쇄시키면 된다.

path compression 까지 사용할 경우 게이트를 찾는 시간복잡도가 이상적으로 O(1)로 감소한다. (최악의 경우 O(logN))

# union-find 를 트리 자료구조로서 바라보는 시선이 필요하다.
# 자리를 효율적으로 배정하는 문제에서 union-find 를 사용하는 시각을 주는 좋은 문제다.
*/
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100005;

int p[SIZE];

void make_set(int x) { p[x] = x; }

// find by path compression
int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
        return p[x] = find(p[x]);
    }
}

void uni(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    p[rootX] = rootY;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int G, P;
    cin >> G >> P;
    for (int i = 0; i <= G; i++) {
        make_set(i);
    }
    int cnt = 0;
    for (int i = 1; i <= P; i++) {
        int g;
        cin >> g;
        int pg = find(g);
        if (pg == 0) break;
        cnt++;
        uni(pg, pg - 1);
    }
    cout << cnt;
    return 0;
}