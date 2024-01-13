#include <bits/stdc++.h>
using namespace std;

// 진법을 이용해 경우의 수를 구현합니다.

int n, k; // n 자리수, k 경우의 수 범위

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 10^n 의 경우
    // 그냥 0부터 순차적으로 출력하면 됩니다.
    n = 3;
    k = 1;
    for(int i=0; i<n; i++) k *= 10;
    for(int i=0; i<k; i++)
        cout << i << '\n';

    // 2^n 의 경우
    n = 10;
    k = 1 << n;
    for(int i=0; i<k; i++) {
        int tmp = i;
        for(int j=0; j<n; j++) {
            cout << tmp % 2;
            tmp /= 2;
        }
        cout << '\n';
    }

    // 3^n 의 경우
    n = 8;
    k = 1;
    for(int i=0; i<n; i++) k *= 3;
    for(int i=0; i<k; i++) {
        int tmp = i;
        for(int j=0; j<n; j++) {
            cout << tmp % 3;
            tmp /= 3;
        }
        cout << '\n';
    }

    // 4^n 의 경우
    // 예를 들어, CCTV의 방향을 동서남북 4방향으로 볼 수 있다고 합시다. 8개의 CCTV가 방향을 잡는 경우의 수는 4^8 입니다.
    // 이를 백트래킹으로 구현할 수도 있지만, 4진법 기반의 수를 이용해서도 구할 수 있습니다.
    // 경우의 수는 총 00000000 부터 33333333 까지 4^8 개 입니다.
    n = 8;
    k = 1 << n*2;
    for(int i=0; i<k; i++) {
        int tmp = i;
        for(int j=0; j<n; j++) {
            cout << tmp % 4;
            tmp /= 4;
        }
        cout << '\n';
    }

    return 0;
}