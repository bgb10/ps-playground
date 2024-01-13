/*
이진 탐색을 활용한 풀이

두 용액을 선택하는 것을 O(N^2) 로 먼저 생각할 수 있다. 하지만 시간초과가 난다.
두 용액의 특성값의 합이 최대한 0에 근접하다는 것은, 어떤 한 용액 a를 선택했을 때 -a와 가장 가까운 용액을
선택해서 더했을 때 합이 최대한 0에 근접하게 된다.
lower_bound 를 사용해 -a가 들어갔을 때 수열의 오름차순이 유지되는 위치를 구하면, 현재위치와 왼쪽, 오른쪽에 위치한
3가지 위치 중 최소값을 확인하면 된다.
이를 통해 O(NlgN) 으로 시간복잡도를 줄일 수 있다.

# 선택한 용액의 위치와 합했을 때 0에 가까운 또다른 용액의 위치가 겹칠 수도 있다. 이 경우를 예외처리해줘야 한다.
# 2467 용액 문제와 거의 유사하다.
# 이분 탐색 문제이기 때문에 투 포인터로도 풀 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[100002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int mnabs = abs(a[0] + a[1]);
    int mn = a[0] + a[1];
    for(int i=0; i<n-1; i++) {
        int b = -a[i];
        int bidx = lower_bound(a+i+1, a+n, b) - a;
        int blidx = bidx - 1;
        int bridx = bidx + 1;
        if((bidx >= 0 && bidx < n) && mnabs > abs(a[i] + a[bidx])) {
            mnabs = abs(a[i] + a[bidx]);
            mn = a[i] + a[bidx];
        }
        if(blidx != i && (blidx >= 0 && blidx < n) && mnabs > abs(a[i] + a[blidx])) {
            mnabs = abs(a[i] + a[blidx]);
            mn = a[i] + a[blidx];
        }
        if((bridx >= 0 && bridx < n) && mnabs > abs(a[i] + a[bridx])) {
            mnabs = abs(a[i] + a[bridx]);
            mn = a[i] + a[bridx];
        }
    }
    cout << mn;
	return 0;
}