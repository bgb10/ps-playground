/*
위상정렬과 우선순위 큐(최소 힙)을 사용해서 풀 수 있다.

일반적인 위상 정렬을 수행하는데, 최대한 낮은 난이도(번호)를 우선 방문해야 한다.
따라서 다음 방문할 노드를 저장하는 자료구조를 큐나 스택 대신 '우선순위 큐 - 최소 힙'을 사용하면 된다.

# 조금만 생각하면 쉬운 문제다. 냠냠.
*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int indeg[32003];
vector<int> adjs[32003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        indeg[v]++;
        adjs[u].push_back(v);
    }

    priority_queue<int, vector<int>, greater<int>> mnhp;
    for(int u = 1; u <= n; u++) {
        if(indeg[u] == 0) mnhp.push(u);
    }

    while(!mnhp.empty()) {
        int cur = mnhp.top();
        mnhp.pop();
        cout << cur << ' ';
        for(int nxt : adjs[cur]) {
            indeg[nxt]--;
            if(indeg[nxt] == 0) {
                mnhp.push(nxt);
            }
        }
    }
    return 0;
}