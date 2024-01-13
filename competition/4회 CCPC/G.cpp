/*
사실 모르는 개념이 들어간 문제였다. 논리의 비약이 있는줄 모르고
계속 붙잡고 있었다. 사실 내가 아는 개념으로는 풀기 힘든 문제.

# 반례를 통해 논리의 비약을 찾아내자.
# 알고리즘에 대한 지식을 넓히자. 지금은 아는 알고리즘이 너무 적다.
*/

#include <bits/stdc++.h>
using namespace std;

unordered_set<int> isolated;
vector<int> adjs[200002];
long long degree[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    // 아... degree가 0이 아닌데도 도달 불가능한 경우가 있구나...
    // 이 논리에는 비약이 있다...
    bool connected = true;
    for(int i=1; i<=n; i++) {
        if(degree[i] == 0) {
            connected = false;
            isolated.insert(i);
        }
    }
    if(connected) cout << "CONNECT\n";
    else cout << "DISCONNECT\n";
    for(int i=0; i<n; i++) {
        int cur;
        cin >> cur;
        if(i == n-1) {
            cout << "DISCONNECT\n";
            exit(0);
        }
        if(isolated.find(cur) != isolated.end()) 
            isolated.erase(cur);
        else {
            for(int adj : adjs[cur]) {
                if(degree[adj] <= 0) continue;
                degree[adj]--;
                if(degree[adj] <= 0) {
                    isolated.insert(adj);
                }
                degree[cur]--;
            }
        }
        if(isolated.empty()) cout << "CONNECT\n";
        else if(i == n-2) cout << "CONNECT\n";
        else cout << "DISCONNECT\n";
    }
    return 0;
}