/*
테스트 케이스의 모든 쌍에 대해 GCD를 구하고 합하면 되는 문제.

시간복잡도는 O(T * N^2 * log(N)) 이다.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[105];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n, greater<>());

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(a[i], a[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}