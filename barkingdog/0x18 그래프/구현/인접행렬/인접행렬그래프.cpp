#include <bits/stdc++.h>
using namespace std;

// 노드와 노드사이 간선이 1개 이하라고 가정
bool adj_matrix_directed[10][10];
bool adj_matrix_undirected[10][10];

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
        adj_matrix_directed[u][v] = 1;
    }
    // Undirected Graph
    cout << "Undirected Graph" << '\n';
    cin >> vc >> ec;
    for(int i=0; i<ec; i++) {
        int u, v;
        cin >> u >> v;
        adj_matrix_undirected[u][v] = 1;
        adj_matrix_undirected[v][u] = 1;
    }
    return 0;
}