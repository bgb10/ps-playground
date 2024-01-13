/*
문제를 그래프로 추상화하고, 모든 지역 사이의 거리를 구해야 하므로 플로이드를 이용할 수 있다.
플로이드를 통해 모든 정점 사이의 거리를 구한 다음, 각 정점마다 탐색 거리 내에서 얻은 아이템 합의 최대값을 구하면 된다.

시간복잡도는 O(N^3) 이다.

# 양방향 그래프임에 주의하자. 문제에서 a->b 를 주면 b->a 는 알아서 넣어야 한다.
*/
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 105;
const int INF = 0x3f3f3f3f;

int item[SIZE];
int dp[SIZE][SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + n + 1, INF);
    }
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);  // 양방향임에 주의!
    }
    // 플로이드를 통해 각 노드간의 거리 구하기
    for (int v = 1; v <= n; v++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[v][j]);
            }
        }
    }

    // 최대 아이템 개수 구하기
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] <= m) {
                cnt += item[j];
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}