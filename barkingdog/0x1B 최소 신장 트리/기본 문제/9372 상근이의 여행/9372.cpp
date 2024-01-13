/*
그래프로 문제를 추상화했을 때, 노드 사이의 거리가 모두 같고 주어진 그래프가 연결그래프이므로,
MST를 구하면 되고, MST의 가중치의 합은 '노드의 개수-1' 이다.

# 엄청 쉬운 문제이다. 어렵게 풀 필요가 전혀 없는 문제.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
        }
        cout << n-1 << '\n';
    }
    return 0;
}