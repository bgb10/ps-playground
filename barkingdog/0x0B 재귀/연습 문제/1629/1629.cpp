#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mul(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    if(b % 2) return (a * mul(a, b-1, c)) % c;
    else {
        ll r = mul(a, b / 2, c);
        return (r * r) % c;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << mul(a, b, c);

    return 0;
}