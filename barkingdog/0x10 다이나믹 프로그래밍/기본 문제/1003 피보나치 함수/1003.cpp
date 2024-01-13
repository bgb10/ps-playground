/*
n 이 크기 때문에 재귀로만 피보나치 함수를 계산할 경우 시간 에 해결할 수 없다.
하지만 dp를 적용하면 O(n) 안에 해결할 수 있다.
또한 매 테스트케이스마다 dp를 적용할 필요가 없다. 처음부터 n=40 까지 계산해놓고 계속 사용하면 된다.
dp 식을 구하면, fibo0[i] = fibo0[i-1] + fibo0[i-2], fibo1[i] = fibo1[i-1] + fibo2[i-2] 이다.
*/
#include <bits/stdc++.h>
using namespace std;

int fibo0[41];
int fibo1[41];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    fibo0[0] = 1;
    fibo1[0] = 0;
    fibo0[1] = 0;
    fibo1[1] = 1;
    for(int i=2; i<=40; i++) {
        fibo0[i] = fibo0[i-1] + fibo0[i-2];
        fibo1[i] = fibo1[i-1] + fibo1[i-2];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << fibo0[n] << ' ' << fibo1[n] << '\n';
    }
	return 0;
}