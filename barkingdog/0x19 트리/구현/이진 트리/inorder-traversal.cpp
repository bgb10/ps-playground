#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};  // index 노드의 left child 노드
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};  // index 노드의 right child 노드

void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << cur << ' ';
    if (rc[cur] != 0) inorder(rc[cur]);
}

// inorder(1);