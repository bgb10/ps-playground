#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};  // index 노드의 left child 노드
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};  // index 노드의 right child 노드

// 루트 노드에서 BFS 를 돌리면 level order traversal
void level_order() {
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        if (lc[cur] != 0) Q.push(lc[cur]);
        if (rc[cur] != 0) Q.push(rc[cur]);
    }
}