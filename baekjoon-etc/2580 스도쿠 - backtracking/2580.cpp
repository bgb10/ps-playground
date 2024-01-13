/*
0인 칸에 들어갈 수 있는 수를 넣어서 경우를 따져보는 백트래킹 문제이다.
n이 작고, pruning 할 때 현재 내가 위치한 3*3 칸, 가로, 세로에 따라 수를 pruning 할 수 있기 때문에
백트래킹으로 푸는 것으로 추측할 수 있다.
현재 0인 칸에 대해 들어갈 수 있는 수를 찾고, 다음 칸으로 이동하고를 반복하고, 안되면 돌아오고 하는
식으로 구현하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int sudoku[12][12];
vector<pair<int, int>> zeros;

void solve(int k) {
    if (k == zeros.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
        return;
    }
    int cnt[12];
    fill(cnt, cnt + 12, 0);
    // 3*3
    for (int i = (zeros[k].X / 3) * 3; i <= (zeros[k].X / 3) * 3 + 2; i++) {
        for (int j = (zeros[k].Y / 3) * 3; j <= (zeros[k].Y / 3) * 3 + 2; j++) {
            cnt[sudoku[i][j]]++;
        }
    }
    // 가로
    for (int j = 0; j < 9; j++) {
        cnt[sudoku[zeros[k].X][j]]++;
    }
    // 세로
    for (int i = 0; i < 9; i++) {
        cnt[sudoku[i][zeros[k].Y]]++;
    }
    // 없는 수 파악 및 다음항 호출
    for (int p = 1; p <= 9; p++) {
        if (cnt[p] != 0) continue;
        sudoku[zeros[k].X][zeros[k].Y] = p;
        solve(k + 1);
        sudoku[zeros[k].X][zeros[k].Y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) zeros.push_back({i, j});
        }
    }
    solve(0);
    return 0;
}