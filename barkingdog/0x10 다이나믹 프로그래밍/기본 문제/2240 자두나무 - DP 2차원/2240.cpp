/*
DP 를 활용해서 풀 수 있는 문제

원래는 O(2^T)의 시간복잡도를 O(TW) 로 줄일 수 있다.
나무1 아래에서 시작해서, 이전에 움직였을 때의 위치와 먹은 자두의 개수를 기록한다.
그리고 시간에 따라 해를 쌓아나가고 나서, 움직인 횟수가 w 보다 작거나 같을 때 T초대까지 먹은 자두 개수 중 최대값을 고르면 된다.
전체 문제는 T초대에 w까지 움직일 수 있을 때 먹은 최대 자두 개수이고,
부분 문제는 i초대 j번 움직였을 때 먹은 자두 개수이다.

쉬운 dp 문제는 dp 에서 항의 변수가 하나지만(예를 들어, 피보나치 수열은 이전 수만 그대로 이어받으면 된다.),
난이도가 조금 있어지면 항의 변수가 여러개일 수 있다(이 문제에서는 t, w 가 부분 문제의 관계에 들어간다고 할 수 있다.)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1004][32]; // 초, 움직인 횟수
int cur[1004][32]; // 움직인 횟수에 따른 현재 위치 저장하는 또 다른 dp 배열

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t, w;
    cin >> t >> w;
    cur[0][0] = 1;
    for(int i=1; i<=t; i++) {
        int jadu;
        cin >> jadu;
        for(int j=0; j<=31; j++) {
            if(j == 0) {
                cur[i][j] = cur[i-1][j];
                dp[i][j] = dp[i-1][j] + (jadu == cur[i][j]);
            }
            else if(j == i) {
                cur[i][j] = (cur[i-1][j-1] == 1 ? 2 : 1);
                dp[i][j] = dp[i-1][j-1] + (jadu == cur[i][j]);
            }
            else {
                cur[i][j] = cur[i-1][j];
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + (jadu == cur[i][j]);
            }
        }
    }
    int mx = dp[t][0];
    for(int i=0; i<=w; i++) {
        mx = max(mx, dp[t][i]);
    }
    cout << mx;
	return 0;
}