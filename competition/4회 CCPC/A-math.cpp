/*
쉬운 문제라고 변수명도 막 짓고, 계획도 없이 풀면 안된다.
n이 홀수, 짝수냐에 따라, 그리고 왼쪽, 오른쪽 방향으로 가냐에 따라 몬스터를 만날 수도 있고, 안 만날 수도 있다.
상황을 그림으로 표현해서 조건에 따른 분기를 적절히 해야하는 문제이다.

변수가 뭘 의미하는지를 확실히 정의하고 문제를 풀자. 이런 쉬운 문제에서 시간을 벌어야 한다.
# n 이 세로, m 이 가로이다. 햇갈리지 말자.
# sr 는 세로, sc 는 가로이다. 햇갈리지 말자.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a, d;
    cin >> a >> d;
    int sr, sc;
    cin >> sr >> sc;
    if (n % 2 == 1) {
        if (d == 0) {
            if (sr == n)
                cout << "YES!";
            else
                cout << "NO...";
        } else {
            cout << "NO...";
        }
    } else {
        if (d == 0) {
            cout << "NO...";
        } else {
            if (sr == n)
                cout << "YES!";
            else
                cout << "NO...";
        }
    }
    return 0;
}