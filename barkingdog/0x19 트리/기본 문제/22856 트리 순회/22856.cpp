/*
중위 순회를 통해 마지막 노드를 파악한 후,
유사 중위 순회를 하면서 마지막 노드에 도달하기 전까지 방문한 노드의 개수를 센다.
이후 트리의 성질 '방문한 노드의 개수 - 1 = 간선의 개수' 를 통해,
이동한 횟수를 셀 수 있다.

# 트리의 성질 '방문한 노드의 개수 - 1 = 간선의 개수' 를 사용하자.
# 중위 순회
*/
#include <bits/stdc++.h>
using namespace std;

int lc[100002];
int rc[100002];

int visited_cnt = 0; // 방문한 노드의 개수
int last = 0; // 중위 순회를 통해 파악한 마지막 방문 노드

void dfs_inorder(int cur) {
    if (lc[cur] != -1) dfs_inorder(lc[cur]);
    last = cur;
    if (rc[cur] != -1) dfs_inorder(rc[cur]);
}

void dfs_similar_inorder(int cur) {
    if (lc[cur] != -1) {
        dfs_similar_inorder(lc[cur]);
        visited_cnt++;
    }

    visited_cnt++;
    if (cur == last) {
        cout << visited_cnt - 1;
        exit(0);
    }

    if (rc[cur] != -1) {
        dfs_similar_inorder(rc[cur]);
        visited_cnt++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
    }
    dfs_inorder(1);
    dfs_similar_inorder(1);
    return 0;
}