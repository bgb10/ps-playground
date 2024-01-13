#include <bits/stdc++.h>
using namespace std;

int edge[10][2]; // v 와 u 사이의 간선 표시
int deg[10]; // 각 정점의 outdegree
int* adj[10];
int idx[10]; // adj[i] 에서 새로운 정점을 추가할 때의 위치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vc, ec;
    // Directed Graph
    cin >> vc >> ec;
    // 각 정점의 outdegree 세기
    for(int i=0; i<ec; i++) {
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++;
    }
    // 각 정점의 outdegree 에 따라 동적 배열 할당
    for(int i=1; i<=vc; i++) {
        adj[i] = new int[deg[i]];
    }
    // 간선에 따라 인접 행렬 완성하기
    for(int i=0; i<ec; i++) {
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v;
        idx[u]++;
    }
    // Undirected Graph
    fill(idx, idx+10, 0);
    cin >> vc >> ec;
    // 각 정점의 degree 세기
    for(int i=0; i<ec; i++) {
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++;
        deg[edge[i][0]]++;
    }
    // 각 정점의 degree 에 따라 동적 배열 할당
    for(int i=1; i<=vc; i++) {
        adj[i] = new int[deg[i]];
    }
    // 간선에 따라 인접 행렬 완성하기
    for(int i=0; i<ec; i++) {
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v;
        adj[v][idx[v]] = u;
        idx[u]++;
        idx[v]++;
    }
    return 0;
}