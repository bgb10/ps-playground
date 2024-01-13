/*
위상 정렬의 개념만 알면 풀 수 있는 문제이다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> di[1002];
int indegree[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int k;
        cin >> k;
        int u, v;
        cin >> u;
        k--;
        while (k--) {
            cin >> v;
            di[u].push_back(v);
            indegree[v]++;
            u = v;
        }
    }
    queue<int> Q;
    for (int u = 1; u <= n; u++) {
        if (indegree[u] == 0) Q.push(u);
    }
    vector<int> seq;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        seq.push_back(cur);
        for (int nxt : di[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) Q.push(nxt);
        }
    }
    if (seq.size() != n) {
        cout << 0;
    } else {
        for (int i : seq) {
            cout << i << '\n';
        }
    }
    return 0;
}