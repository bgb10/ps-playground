/*
에라토스테네스의 체와 투 포인터를 이용해서 풀 수 있는 문제.

sieve 를 통해 소수를 구하고, 소수의 연속합이 n이 되는 경우를 구하면 된다.
연속합이 구할 때 투 포인터를 사용할 수 있다.
st 와 en 두 포인터를 두고, n 보다 작을 때 en 을 증가시키고, n 보다 작을 때는 st 를 증가시키면서
연속합을 구하면 된다.

# 1806 부분합 문제와 유사.
# 투 포인터 문제 특성상 edge case 에 주의하자.
*/

#include <bits/stdc++.h>
using namespace std;

bool isprime[4000001];
vector<int> primes;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    fill(isprime, isprime+n+1, 1);
    // sieve
    for(int i=2; i*i<=n; i++) {
        if(!isprime[i]) continue;
        for(int j=i+i; j<=n; j+=i) {
            isprime[j] = 0;
        }
    }
    for(int i=2; i<=n; i++) {
        if(!isprime[i]) continue;
        primes.push_back(i);
    }
    // two pointer
    auto st = primes.begin(), en = primes.begin();
    int psum = 0;
    int ans = 0;
    while(st != primes.end()) {
        if(psum < n) {
            if(en == primes.end()) break;
            psum += *en;
            en++;
        }
        else if(psum > n) {
            psum -= *st;
            st++;
        }
        else {
            ans++;
            if(en == primes.end()) break;
            psum += *en;
            en++;
        }
    }
    cout << ans;
    return 0;
}