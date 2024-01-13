#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[100002];
int p[100002]; // 부모 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // 인접 리스트 채우기
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    // BFS
    queue<int> Q;
    p[1] = 0;
    Q.push(1);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int nxt : adjs[cur]) {
            if(p[cur] == nxt) continue;
            p[nxt] = cur;
            Q.push(nxt);
        }
    }
    for(int i=2; i<=n; i++) {
        cout << p[i] << '\n';
    }
    return 0;
}