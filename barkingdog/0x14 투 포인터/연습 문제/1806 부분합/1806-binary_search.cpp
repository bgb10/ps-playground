/*
누적합과 이분탐색을 이용한 풀이

1~N 까지의 누적합을 구하고, 누적합의 차가 곧 구간의 합임을 이용한 풀이이다.
이때 누적합의 차가 s 이상이 되어야 하는데, 이를 찾기 위해 이분탐색을 사용했다.
Sk - Sp >= s 인 것을 구하는데, Sp = Sk - s 에 대해 lower_bound 를 사용하면 
Sk - Sp = s 인 p를 찾거나, p가 존재하지 않는다는 것을 찾을 수 있다.
Sn 에서부터 시작할 것이기 때문에 p 가 존재하지 않는 순간 for문을 끝낼 수 있다. 

# 시간복잡도는 O(NlgN) 이다. 투포인터로 풀면 O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int as[100004]; // 누적합(accumulated sum)

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int a;
    as[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> a;
        as[i] += a + as[i-1];
    }
    int mlen = INT_MAX;
    for(int i=n; i>=1; i--) {
        int idx = lower_bound(as, as+i, as[i] - s) - as;
        if(as[i] - as[idx] < s) {
            if(idx == 0) break;
            mlen = min(mlen, i - (idx - 1));
        }
        else if(as[i] - as[idx] == s) {
            mlen = min(mlen, i - idx);
        }
    }
    cout << (mlen == INT_MAX ? 0 : mlen);
	return 0;
}