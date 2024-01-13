/*
투 포인터를 이용한 풀이.

합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하면 된다.
따라서, "더 긴 것의 길이를 구하기 위해 추가로 탐색할 필요는 없다" 는 발상으로
문제를 풀어야 한다.

[st, en) 까지의 수의 구간합을 구하고, 이것이 s 보다 클 경우 최소 길이를 구한다.

# O(N)의 풀이. 이분탐색으로 풀면 O(NlgN) 이다.
# en 이 열린구간임에 주의하자.
*/

#include <bits/stdc++.h>
using namespace std;

int a[100002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int st = 0, en = 0;
    int psum = 0;
    int mlen = INT_MAX;
    while(en <= n) {
        if(psum < s) {
            if(en == n) break;
            psum += a[en];
            en++;
        }
        else {
            mlen = min(mlen, en - st);
            psum -= a[st];
            st++;
        }
    }
    cout << (mlen == INT_MAX ? 0 : mlen);
	return 0;
}