#include <bits/stdc++.h>
using namespace std;

// 노드와 노드사이 간선이 1개 이하라고 가정
vector<int> adj_list_directed[10];
vector<int> adj_list_undirected[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vc, ec;
    // Directed Graph
    cout << "Directed Graph" << '\n';
    cin >> vc >> ec;
    for(int i=0; i<ec; i++) {
        int u, v;
        cin >> u >> v;
        adj_list_directed[u].push_back(v);
    }
    // Undirected Graph
    cout << "Undirected Graph" << '\n';
    cin >> vc >> ec;
    for(int i=0; i<ec; i++) {
        int u, v;
        cin >> u >> v;
        adj_list_undirected[u].push_back(v);
        adj_list_undirected[v].push_back(u);
    }
    return 0;
}