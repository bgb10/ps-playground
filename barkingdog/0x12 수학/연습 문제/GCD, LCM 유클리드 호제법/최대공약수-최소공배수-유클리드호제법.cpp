#include <bits/stdc++.h>

#include <numeric>
#include <ratio>
using namespace std;

// 유클리드 호제법의 시간복잡도는 O(logN) 이다.
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // overflow 방지 위해 a 에 gcd 를 먼저 나눔.
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << "최대공약수 gcd" << '\n';
    cout << "직접 정의: " << gcd(a, b) << '\n';
    cout << "gcc 에 있는 gcd: " << __gcd(a, b) << '\n';
    // numeric 헤더파일에는 c++17 부터 들어간다. 지금 버젼은 c++14이다.

    cout << '\n';

    cout << "최소공배수 lcm" << '\n';
    cout << "직접 정의(최대공약수 * 최소공배수 = A * B 사용): " << lcm(a, b) << '\n';
    return 0;
}