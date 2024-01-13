#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll GCD(ll a, ll b) {
    return b ? GCD(b, a % b) : a;
}

// 굳이 숫자로 만들 필요가 없이, 문자로 처리하면 된다.
// 큰 숫자는 처리할 때 예상치 못한 오류가 날 확률이 매우 높기 때문.
ll eleven(ll n) {
    ll res = 0;
    ll k = 1;
    for(ll i=0; i<n; i++) {
        res += k;   
        k *= 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    int res = GCD(a, b);
    // long long 을 직접 출력하는 것보다 문자를 여려번 출력
    for(int i=0; i<res; i++) // 정답이 천만 자리를 넘지 않기 때문에 O(n) 안에 출력 가능
        cout << 1;
    return 0;
}