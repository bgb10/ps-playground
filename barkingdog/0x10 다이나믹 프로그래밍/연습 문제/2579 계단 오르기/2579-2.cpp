/*
DP 로 푸는 문제.

전체 문제는 계단을 밟아서 얻을 수 있는 점수의 최대값(최적해) 이다.
여기서 최적 부분 구조를 가진 부분문제로 쪼개면, i 번째 계단까지 밟았을 때 얻을 수 있는 점수의 최대값(최적해)이다.
이 부분 문제를 통해 마지막 계단까지 최적해를 쌓아나가면 풀 수 있다.

정리하면,
테이블 정의: x[a][b] : a 계단까지 갔을 때 b 만큼 연속된 계단을 밟았을 때 얻을 수 있는 점수의 최대값 이다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[304];
int x[304][3];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    x[1][1] = a[1]; x[2][1] = a[2];
    x[1][2] = 0; x[2][2] = a[1] + a[2];
    for(int i=3; i<=n; i++) {
        x[i][1] = max(x[i-2][1], x[i-2][2]) + a[i];
        x[i][2] = x[i-1][1] + a[i];
    }
    cout << max(x[n][1], x[n][2]);
	return 0;
}