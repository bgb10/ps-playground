/*
백트래킹과 이차원 배열 이동을 활용한 문제이다.

각 좌표의 방문 횟수를 기록한 후, 방문 횟수가 1회 이상이면 더 이상 방문하지 않는다.
이를 통해 이동 경로가 단순한 경로만을 구할 수 있다.

# cout 의 기본 double 형 출력이 소수점 8째짜리(10^-8)까지기 때문에, 상대오차가 10^-9 까지 허용될 경우
오차 범위를 만족하지 못한다. 따라서 이를 조절해주어야 한다.(예제에서는 11자리까지 출력)
# 평소에 음수 좌표에 대해 고려를 안해봐서 계속 overflow 나 segfault 가 났던 것 같다. 
음수 좌표까지 고려해서, 시작 좌표를 (20, 20) 으로 했으면 됐는데, (0, 0) 으로 하니 에러가 났다.
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// 동서남북 순
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n;
int visited_cnt[40][40];
double move_prob[4];

double solve(int k, pair<int, int> cur, double prob) {
    if (k == n) {
        return prob;
    }

    double tmp = 0;
    for (int i = 0; i < 4; i++) {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];

        if (visited_cnt[nx][ny] >= 1) continue;
        visited_cnt[nx][ny]++;
        tmp += solve(k + 1, {nx, ny}, prob * move_prob[i]);
        visited_cnt[nx][ny]--;
    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < 4; i++) {
        cin >> move_prob[i];
        move_prob[i] /= 100.0;
    }
    visited_cnt[20][20]++;
    cout.precision(11); // cout 의 소수점 출력을 11자리로 변경
    cout << solve(0, {20, 20}, 1);
    return 0;
}