/*
a + b + c = 0 인 쌍을 찾는 것을 a + b = -c 로 치환해서 이분탐색으로 푸는 문제.

a + b 에 대해 2중 for문을 돌면서, 이에 대응되는 -c 가 존재하는지 이분탐색으로 확인하면 된다.

# 보통 N=10000 인 경우 O(N^2) 일 경우 TLE가 나나, 해당 문제는 시간 제한을 넉넉하게 4초를 주었기 때문에 
N^2lgN 풀이로도 통과한다.
# 시간이 넉넉하지 않아서 같은 N^2lgN 이라도 계산을 중복해서 하면 TLE가 날 수 있다.
이분탐색하는 범위가 이전에 탐색한 범위에 중복되지 않는지 잘 고려하자.
*/

#include <bits/stdc++.h>
using namespace std;

int s[10004];
int n;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    sort(s, s+n);
    long long cnt = 0;
    for(int a=0; a<n-1; a++) {
        for(int b=a+1; b<n; b++) {
            int apb = s[a] + s[b];
            int c = -apb;
            int lidx = lower_bound(s+b+1, s+n, c) - s;
            if(s[lidx] != c) continue;
            int uidx = upper_bound(s+b+1, s+n, c) - s;
            cnt += uidx - lidx;
        }
    }
    cout << cnt;
	return 0;
}