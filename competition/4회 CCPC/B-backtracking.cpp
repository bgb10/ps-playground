/*
문제를 보자마자 비트마스킹을 사용하면 되는지 알았지만, 자신이 없어 백트래킹으로 푼 문제.
쉬운 문제를 너무 어렵게, 복잡하게 풀었다.
설계없이 무작정 풀면 이렇게 복잡하게 푼다는걸 다시금 느낀 문제이다.

# 2진수의 각 자리수가 주어지면 10진수를 연속적으로 만들 수 있다는 사실을 간과했다.
# 비트마스킹 문제임에도 자신이 없어서 힘든 길을 택했다.
*/

#include <bits/stdc++.h>
using namespace std;

int s, m;
int cur = 0;
int cur2 = 0;
vector<int> comb;
vector<int> ahri;
vector<int> kugi;
vector<int> kugisum;

void solve(int k) {
    if (k == 10) {
        ahri.push_back(cur);
        if (cur == m) kugi = comb;
        return;
    }
    cur += 1 << k;
    comb.push_back(1 << k);
    solve(k + 1);
    cur -= 1 << k;
    comb.pop_back();

    solve(k + 1);
}

void solve2(int k) {
    if (k == kugi.size()) {
        kugisum.push_back(cur2);
        return;
    }
    cur2 += kugi[k];
    solve2(k + 1);
    cur2 -= kugi[k];

    solve2(k + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> m;
    solve(0);  // 쿠기의 돈 구성 찾기.
    sort(ahri.begin(), ahri.end());
    int balance = 0;
    for (auto it = ahri.rbegin(); it != ahri.rend(); it++) {
        if (*it == s) {
            cout << "No thanks";
            exit(0);
            break;
        } else if (*it < s) {
            balance = s - *it;
            break;
        }
    }
    solve2(0);
    for (auto it = kugisum.rbegin(); it != kugisum.rend(); it++) {
        if (balance == *it) {
            cout << "Thanks";
            exit(0);
        }
    }
    cout << "Impossible";
    return 0;
}