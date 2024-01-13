/*
자식과 시조 요소 간의 선후관계가 존재하기 때문에 위상정렬로 해결하면 된다.

자식 노드가 없는 최하단 노드부터 위로 올라가는 방식으로 위상정렬을 수행했는데,
이는 위상정렬 조건에 위배된다.
부모가 있어야 자식이 있는 것이지, 자식이 먼저 있어야 부모가 있는게 아니기 때문이다.
그래서 10/19 만 맞은 것이다.
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> p;
unordered_map<string, int> ptoindeg;
unordered_map<string, int> ptoindegori;
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
        ptoindegori[s] = 0;
    }
    sort(p.begin(), p.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        ptooutdeg[u]++;
        ptoindeg[v]++;
        ptoindegori[v]++;
        adjs[u].push_back(v);
    }

    queue<string> Q;
    for (auto it = ptoindeg.begin(); it != ptoindeg.end(); it++) {
        if (it->second == 0) {
            Q.push(it->first);
        }
    }
    while (!Q.empty()) {
        string cur = Q.front();
        Q.pop();
        for (string nxt : adjs[cur]) {
            ptoindeg[nxt]--;
            if (ptoindeg[nxt] == 0) {
                ptochilds[nxt].push_back(cur);
                Q.push(nxt);
            }
        }
    }

    vector<string> roots;
    for (auto it = ptooutdeg.begin(); it != ptooutdeg.end(); it++) {
        if (it->second == 0 && ptoindegori[it->first] != 0) {
            roots.push_back(it->first);
        }
    }
    sort(roots.begin(), roots.end());

    cout << roots.size() << '\n';
    for (string s : roots) {
        cout << s << ' ';
    }
    if (!roots.empty()) cout << '\n';
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