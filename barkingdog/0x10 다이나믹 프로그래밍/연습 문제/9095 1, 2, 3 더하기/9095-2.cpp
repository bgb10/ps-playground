/*
항 사이의 관계를 관찰해서 푸는 문제.

x[i] 를 "1,2,3 을 더해서 i 를 만드는 경우의 수" 라고 정하고 항을 구하면
x[1] = 1, x[2] = 2, x[3] = 4 이고, x[4] = 7인 것을 알 수 있다.
수를 나열해서 관찰해보면 x[i] 에 대해 x[i-1], x[i-2], x[i-3] 에 각각 1, 2, 3 을 뒤에 붙였을 때 x[i] 가 만들어지는 것을 볼 수 있다.
따라서 x[i] = x[i-1] + x[i-2] + x[i-3] 이다.

x[i] 를 x[i-1], x[i-2], x[i-3] 이라는 부분문제를 통해 푸는 DP 문제이다.

# n 이 작아서 백트래킹이나 10중 for문으로도 풀 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int x[15];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    x[1] = 1;
    x[2] = 2;
    x[3] = 4;
    for(int i=4; i<=10; i++) {
        x[i] = x[i-1] + x[i-2] + x[i-3];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << x[n] << '\n';
    }
	return 0;
}