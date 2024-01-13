/*
최적화 문제를 결정 문제로 바꾸는 parametric search 기법으로 풀 수 있는 문제이다.

조카에게 줄 수 있는 막대 과자의 최대 길이를 구하는 문제를(최적화 문제),
막대 과자의 길이가 i 일때 조카 m 명에게 모두 배분할 수 있는가?(결정문제) 로 치환해서 풀면 된다.
이때 막대 과자의 길이를 1부터 선형적으로 볼 필요 없이,
이분탐색을 이용해서 찾아가면 된다. (막대 과자의 길이에 따른 과자가 나눠지는 개수가 반비례 형태의 감소함수(단조함수)이기 때문이다.) 
*/

#include <bits/stdc++.h>
using namespace std;

int L[1000002];
int m, n;

using ll = long long;

ll count_snack(int len) {
    ll sum = 0; 
    for(int i=0; i<n; i++) {
        sum += L[i] / len;
    }
    return sum;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        cin >> L[i];
    }
    int st = 1;
    int en = 1000000000;
    while(st < en) {
        int mid = (st + en + 1) / 2; // 올림을 안해줄 경우 st와 en 이 인접할 때 무한 loop에 빠질 수 있다.
        if(count_snack(mid) >= m) st = mid;
        else en = mid - 1;
    }
    cout << ((count_snack(st) >= m) ? st : 0);
	return 0;
}