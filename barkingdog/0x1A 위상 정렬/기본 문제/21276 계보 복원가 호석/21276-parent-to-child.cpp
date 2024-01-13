/*
자식과 시조 요소 간의 선후관계가 존재하기 때문에 위상정렬로 해결하면 된다.

트리 형태에서 우선되어야 하는 것을 루트 노드로 하고, 자식들을 하위 노드로 표현하면 된다.
예를 들어, u의 조상이 v일때, v는 u보다 우선되어야 한다.
이때 자기 자신의 직계 자식임을 판단하는 법은 하위 노드의 indegree 를 1 줄였을 때 0인지 확인하면 된다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> p;
unordered_map<string, int> ptoindeg;
unordered_map<string, vector<string>> adjs;
unordered_map<string, vector<string>> ptochilds;
unordered_map<string, int> ptooutdeg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        p.push_back(s);
        ptooutdeg[s] = 0;
        ptoindeg[s] = 0;
    }
    sort(p.begin(), p.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        ptooutdeg[v]++;
        ptoindeg[u]++;
        adjs[v].push_back(u);
    }

    vector<string> roots;
    queue<string> Q;
    for (auto it = ptoindeg.begin(); it != ptoindeg.end(); it++) {
        if (it->second == 0) {
            roots.push_back(it->first);
            Q.push(it->first);
        }
    }
    sort(roots.begin(), roots.end());

    while (!Q.empty()) {
        string cur = Q.front();
        Q.pop();
        for (string nxt : adjs[cur]) {
            ptoindeg[nxt]--;
            if (ptoindeg[nxt] == 0) {
                ptochilds[cur].push_back(nxt);
                Q.push(nxt);
            }
        }
    }

    cout << roots.size() << '\n';
    for (string s : roots) {
        cout << s << ' ';
    }
    if(!roots.empty()) cout << '\n';
    for (string s : p) {
        cout << s << ' ';
        cout << ptochilds[s].size() << ' ';
        sort(ptochilds[s].begin(), ptochilds[s].end());
        for (string c : ptochilds[s]) {
            cout << c << ' ';
        }
        cout << '\n';
    }
    return 0;
}