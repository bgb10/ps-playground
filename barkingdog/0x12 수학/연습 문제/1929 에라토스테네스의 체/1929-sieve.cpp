/*
최적화한 에라토스테네스의 체

i) sieve 를 root(M) 까지만 돌아도 된다. 
-> 합성수 N에서 1을 제외한 가장 작은 약수를 x라고 하면, x가 약수일 때 N/x 도 약수이다. 따라서, x <= N/x 이고, x <= root(N) 이 된다.
ii) i 가 소수라면, i*i 이상인 i의 배수부터 걸러도 된다. 
-> i*i 미만인 합성수는 이미 이전에 걸러졌기 때문이다.
*/

#include <bits/stdc++.h>

using namespace std;

bool isprime[1000001];

int main()
{
    fill(isprime, isprime + 1000001, 1);
    int n, m;
    cin >> n >> m;
    isprime[1] = 0;
    for(int i=2; i*i<=m; i++) {
        if(!isprime[i]) continue;
        for(int j = i*i; j <= m; j += i) {
            isprime[j] = 0;
        }
    }
    for(int i=n; i<=m; i++) {
        if(isprime[i]) cout << i << '\n';
    }
    return 0;
}