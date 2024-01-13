/*
트리의 정의와 성질을 이용해서 풀면 되는 문제.

그래프 안에 있는 트리의 개수를 세면 된다.
트리의 정의는 '무방향, 무사이클, 연결그래프' 이다.
따라서 그래프 안의 연결 요소 중에서 위의 조건을 만족하는 그래프의 개수를 찾으면
된다. DFS로 트리를 탐색하는 도중 부모 노드가 아닌 다른 노드를 다시 방문할 경우,
사이클이 존재하는 것으로 판단하고 연결 요소가 트리가 아님을 알 수 있다.
모든 노드를 방문할 때까지 반복하면 된다.

# 하나의 '무방향, 무사이클, 연결그래프' 에 대해 루트가 다르게 트리를 잡아도
이는 모두 같은 트리임에 주의하자.
# BFS 에서 다음 방문할 노드를 저장하는 자료구조만 stack 으로 바꾸면 DFS가 된다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[502];
bool vis[502];
bool isTree = true;

void dfs(int cur, int par) {
    vis[cur] = 1;
    for (int nxt : adjs[cur]) {
        if (vis[nxt]) {
            if (nxt != par) {
                isTree = false;
            }
            continue;
        }
        dfs(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int case_cnt = 1;
    while (1) {
        int n, m;
        cin >> n >> m;
        fill(vis, vis + n + 1, 0);
        fill(adjs, adjs + n + 1, vector<int>());
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }
        int cnt = 0;
        for (int v = 1; v <= n; v++) {
            if(vis[v]) continue;
            dfs(v, 0);
            if (isTree) cnt++;

            // 초기화
            isTree = true;
        }
        cout << "Case " << case_cnt++ << ": ";
        if (cnt > 1) {
            cout << "A forest of " << cnt << " trees.\n";
        } else if (cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "No trees.\n";
        }
    }

    return 0;
}