/*
평소에 안하던 문자열 비교에 대한 사고가 필요했던 문제.
DP 적인 접근(한번만 읽고 기존에 읽었던 내용들을 사용하는 것)은 성공했으나, 익숙하지 않은 풀이라 어떻게 구현할지 감이
안잡혔다. 먼저 I를 읽고, OI가 반복되면 PN의 문자열을 구할 수 있다. 하지만 만약 OI가 반복되다가 끊긴다면, 다음 인덱스로
넘어가면 된다.

생각해보면 굉장히 간단한 풀이다.
'반드시 한번만 읽어야 한다.' 라는 생각에 갇혀서 이 풀이를 생각해내지 못했나 싶다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    string s;
    cin >> n >> m >> s;

    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        int r = 0;
        if (s[i] == 'I') {
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                r++;
                if (r == n) {
                    ans++;
                    r--;
                }
                i += 2;
            }
        }
    }

    cout << ans;
    return 0;
}