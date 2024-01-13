/*
어떻게 보면 굉장히 실용적인(?) 문제다. 친구들 집 사이의 왕복 거리를 구해서 만나기 좋은 장소를 찾는 문제.
친구들 집을 노드, 사이의 거리를 간선으로 표시해서 모든 노드 사이의 거리를 구하는 플로이드 문제다.
n = 200 으로 충분히 플로이드를 사용할 수 있다.

시간복잡도는 O(N^3) 이다.

# 최소거리의 도시가 여러개일 수 있으니 주의!
*/
#include <bits/stdc++.h>
using namespace std;

int dp[205][205];

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++) {
        fill(dp[i], dp[i]+n+1, INF);
    }
    for(int i=0; i<=n; i++) {
        dp[i][i] = 0;
    }
    for(int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        dp[a][b] = min(dp[a][b], t);
    }
    // 플로이드
    for(int v=1; v<=n; v++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[v][j]);
            }
        }
    }
    // 왕복시간이 가장 작을 때의 거리 구하기
    int s;
    cin >> s;
    vector<int> lived;
    for(int i=0; i<s; i++) {
        int c;
        cin >> c;
        lived.push_back(c);
    }
    int dist[205] = {0};
    int mn = INF;
    for(int c=1; c<=n; c++) {
        int mx = 0;
        for(int l : lived) {
            mx = max(mx, dp[c][l] + dp[l][c]);
        }
        dist[c] = mx;
        mn = min(mn, mx); // 최대가 최소가 될 때의 거리
    }

    // 최소 거리에 따른 도시 구하기
    for(int c=1; c<=n; c++) {
        if(dist[c] == mn) {
            cout << c << ' ';
        }
    }
    return 0;
}