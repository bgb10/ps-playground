#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    else if(b % 2) { // b 가 홀수면 (a * a^b-1) % c 를 하고
        return (a * solve(a, b - 1, c)) % c;
    }
    else { // b 가 짝수면 (a^(b/2) * a^(b/2)) % c 를 하면 된다.
        ll r = solve(a, b >> 1, c);
        return (r * r) % c;
    }
    // 수의 범위가 벗어나는 것은 long long 으로 처리하면 간편해진다.
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
    return 0;
}