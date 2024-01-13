/*
Task Scheduling 중 그리디로 해결할 수 있는 문제이다.
꽃을 연속하게 피게 하기 위해서, 꽃이 피어있는 기간이 최대한 길도록 꽃을 선택하면 되고,
이를 통해 추론하면 "매 순간마다 피어있는 시간이 가장 긴(즉, 지는 날짜가 가장 뒤에 있는) 꽃을 선택하면 된다."
이때 꽃은 마지막으로 꽃이 진 시간 이하에서 핀 꽃이어야 할 것이다(이어져야 하니까.)

# 1931 회의실 배정 문제와 거의 유사한 문제이다.
# 날짜 처리를 어떻게 해야할까? 다양한 해결책이 있겠지만, '진수' 의 성질을 이용해보는건 어떨까?
날짜는 각 자리에 최대 31 까지 들어갈 수 있다. 따라서, 일수는 그대로 더하고, 달에는 32를 곱하게 되면
각 날짜에 따른 고유의 숫자가 만들어진다.
날짜 비교를 위해 pair 를 사용하게 된다면 코드가 매우 복잡해지는데, 각 날짜를 수 하나로 대응시키면
훨씬 편할 것이다.
- 해당 풀이에서는 넉넉하게 100진수로 잡았다.
*/

#include <bits/stdc++.h>
#define X first
#define Y second
#define BASE 100
using namespace std;

int n;
pair<int, int> a[100002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        int stmon, stday, enmon, enday;
        cin >> stmon >> stday >> enmon >> enday;
        a[i].X = stmon * BASE + stday;
        a[i].Y = enmon * BASE + enday;
    }
    sort(a, a+n);
    int end = 3 * BASE + 1;
    int goal = 11 * BASE + 30;
    int cnt = 0;
    while(end <= goal) {
        if(cnt > n) {
            cnt = 0;
            break;
        }
        int uidx = upper_bound(a, a+n, make_pair(end, INT_MAX)) - a; // 이전까지 꽃이 피어있었던 기간 내에 핀 꽃을 찾기 위함.
        int mxend = end;
        for(int i=0; i<uidx; i++) {
            mxend = max(mxend, a[i].Y); // 이전까지 꽃이 피어있었던 기간 내에 핀 꽃 중 지는 시간이 가장 뒤인 꽃 선택
        }
        end = mxend;
        cnt++;
    }
    cout << cnt;
	return 0;
}