/*
예시를 들어가면서 수를 좀 관찰하다보면 점화식을 찾을 수 있다.
f(n, s, k) = n + f((n+s)/k, (n+s)%k, k) 이다. (n은 치킨수, s는 도장수, k는 도장 당 치킨수)
치킨 n마리를 먹어도 n개의 도장이 생기기 때문에 이를 잘 감안하자.

# n = 10억 이기 때문에 while 문 10억번 돌리면 터진다! 잘 생각해보도록.
# 개인적으로 실버는 되야하는 문제인 것 같다. 브론즈는 좀...?
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int n, int s, int k) {
    if (n + s < k) // 치킨을 통해서 나오는 도장과 기존의 도장을 합쳐도 치킨 한마리를 얻을 수 없다면
        return n; // 치킨 개수만 반환
    else {
        return n + solve((n + s) / k, (n + s) % k, k);
    }
}

int main() {
    int n, k;
    while (1) {
        cin >> n >> k;
        if (cin.eof()) break;
        cout << solve(n, 0, k) << '\n';
    }
    return 0;
}