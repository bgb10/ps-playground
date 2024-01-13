/*
Task Scheduling Problem 인듯
직관: k일 이전에 핀 꽃 중 가장 늦게 지는 꽃 선택

시간복잡도를 생각해면 애매한데, 이분 탐색이 굳이 필요는 없겠더라. 적용이 안된다.
*/

#include <bits/stdc++.h>
using namespace std;
using tiiii = tuple<int, int, int, int>;
using tii = pair<int, int>;

int n;
tiiii schedule[100002]; // 시작월, 시작일, 종료월, 종료일

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b, c, d;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c >> d;
        schedule[i] = {a,b,c,d};
    }
    sort(schedule, schedule+n);
    tii mxend = {3,1}; // 꽃이 지는 시간
    const tii goal = {11,30}; // 꽃이 계속 피어있어야 하는 기간
    int cnt = 0; // 개수 세기
    int mxidx = 0;
    while(mxend <= goal) { // 꽃이 지는 시간이 11/30 이후일 경우에만 while 문 종료
        if(cnt > n+4) {
            cnt = 0;
            break;
        }
        tiiii bf = make_tuple(mxend.first, mxend.second, 99, 99);
        int uidx = upper_bound(schedule, schedule+n, bf) - schedule; // 이전의 꽃이 지는 시간 이전에 핀 꽃을 찾음.
        tii mxend2 = {-1, -1}; // 최대한 늦게 지는 꽃을 찾기 위함.
        // int mxidx2 = mxidx;
        for(int i=0; i<uidx; i++) { // 이전의 꽃이 지는 시간 이전에 핀 꽃 중 최대한 늦게 지는 꽃 찾기.
            tie(a, b, c, d) = schedule[i];
            tii end = {c, d};
            if(mxend2 < end) { // 더 늦게 지는 꽃을 찾았을 경우
                mxend2 = end;
                // mxidx2 = i;
            }
        }
        mxend = mxend2;
        // mxidx = mxidx2;
        cnt++;
    }
    cout << cnt;
	return 0;
}