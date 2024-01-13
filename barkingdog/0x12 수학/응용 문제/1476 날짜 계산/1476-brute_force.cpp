/*
브루트 포스를 이용한 풀이. 경우의 수가 많지 않을거라 예상함.

이 문제를 세련되게 풀려면 모듈러 성질을 이용한 '중국인의 나머지 정리'를 사용하면 된다.
하지만 증명 과정이 만만하지 않으므로 skip.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ce = 1, cs = 1, cm = 1;
    int cnt = 1;
    int e, s, m;
    cin >> e >> s >> m;
    while (1) {
        if (ce == e && cs == s && cm == m) break;
        cnt++;
        if (ce >= 15)
            ce = 1;
        else
            ce++;
        if (cs >= 28)
            cs = 1;
        else
            cs++;
        if (cm >= 19)
            cm = 1;
        else
            cm++;
    }
    cout << cnt;
    return 0;
}