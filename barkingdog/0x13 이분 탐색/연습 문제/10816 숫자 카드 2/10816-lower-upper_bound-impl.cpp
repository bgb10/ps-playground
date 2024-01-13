/*
lower bound: 수를 넣었을 때 오름차순이 유지되는 가장 왼쪽 위치
upper bound: 수를 넣었을 때 오름차순이 유지되는 가장 오른쪽 위치

구현에서도 알 수 있듯이, 탈출 조건등을 제대로 정의하지 않으면 무한 loop 에 빠지거나 엉뚱한 답을 낼 수 있다.
그림을 그려가면서 조건을 잘 정의하고, 찾는 수가 존재하지 않을때와 st와 en 이 1 차이일 때를 특히 주의하자!
*/

#include <bits/stdc++.h>

using namespace std;

int A[500001];
int n, m;

int lower_idx(int target, int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st + en) / 2;
        if(A[mid] >= target) en = mid; // 같을 때 왼쪽으로 탐색하기 위해 등호가 여기 붙음.
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st + en) / 2;
        if(A[mid] > target) en = mid; 
        else st = mid + 1; // 같을 때 오른쪽으로 탐색하기 위해 등호가 여기 붙음.
    }
    return st;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    sort(A, A+n);
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        // 정렬되어 있을 때 이분탐색을 기반으로 하는 lower, upper bound 함수를 사용해 개수 측정 가능
        cout << upper_idx(k, n) - lower_idx(k, n) << ' ';
    }
    return 0;
}
