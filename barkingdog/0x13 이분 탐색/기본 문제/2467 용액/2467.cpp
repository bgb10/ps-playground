/*
두 혼합 용액을 선택하는 것을 이분탐색을 사용해 시간복잡도를 줄이는 문제.

특성값이 0에 가까운 혼합 용액을 만들기 위해서 두 용액을 그냥 고르면 O(N^2) 이다.
따라서, 효율적으로 혼합 용액을 고르는 방법이 필요하다.
이때 한 용액을 선택했을 때, 나머지 다른 용액은 "두 용액이 혼합되었을 때 0에 가깝도록 해야하는 수"여야 한다.
따라서, "현재 용액 a에 대해 -a와 최대한 가까운 수를 찾는 것"으로 문제를 바꿀 수 있다.
이는 이분 탐색으로 구현이 가능하고, stl 의 lower_bound 를 통해 해결했다.
이때 나머지 용액이 양쪽 끝에 존재하는 용액이면 그냥 합치면 되지만,
아닌 경우는 lower_bound 를 통해 찾은 원소와 그보다 작은 원소 하나를 모두 고려해야 한다.(이웃한 원소가 음수인 경우!)

# lower_bound 는 인자의 수가 정렬된 수열에 들어갔을 때 오름차순이 유지되는 가장 왼쪽 위치를 의미한다.
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
    int mn = abs(a[0] + a[1]);
    int mnl = 0, mnr = 1;
    for(int i=0; i<n-1; i++) {
        int idx = lower_bound(a+i+1, a+n, -a[i]) - a;
        if(idx == i+1) {
            if(abs(a[i] + a[idx]) < mn) {
                mnl = i;
                mnr = idx;
                mn = abs(a[i] + a[idx]);
            }
        }
        else if(idx == n) {
            if(abs(a[i] + a[idx-1]) < mn) {
                mnl = i;
                mnr = idx-1;
                mn = abs(a[i] + a[idx-1]);
            }
        }
        else {
            if(abs(a[i] + a[idx]) < mn) {
                mnl = i;
                mnr = idx;
                mn = abs(a[i] + a[idx]);
            }
            if(abs(a[i] + a[idx-1]) < mn) {
                mnl = i;
                mnr = idx-1;
                mn = abs(a[i] + a[idx-1]);
            }
        }
    }
    cout << a[mnl] << ' ' << a[mnr];
	return 0;
}