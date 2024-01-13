#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

int p[SIZE + 10];

// 에네토스테네스의 체
void sieve() {
    for(int i=0; i<=SIZE; i++)
        p[i] = i;

    for(int i=2; i<=SIZE; i++) {
        if(p[i] == 0) continue;
        for(int j=2*i; j<=SIZE; j+=i)
            p[j] = 0;
    }
}

// 브루트 포스
void solve(int s) {
    for(int i=2; i<=SIZE; i++) {
        for(int j=i; j<=SIZE; j++) {
            for(int k=j; k<=SIZE; k++) { // 문제 조건에 있는 k와 반복문 변수 k가 혼용되지 않도록 주의
                if(p[i] == 0 || p[j] == 0 || p[k] == 0) continue;
                if(p[i] + p[j] + p[k] != s) continue;
                cout << p[i] << ' ' << p[j] << ' ' << p[k] << '\n';
                return;
            }
        }
    }
    cout << 0 << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        solve(k);
    }
    return 0;
}