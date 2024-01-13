/*
뭔가 여러가지 시행을 거쳐야 할 것 같고 정말 어려운 문제 같지만,
사실 LIS(최장 길이 증가 수열) 문제.

수열을 관찰해보면 수열 내에 증가 부분 수열을 찾은 후, 나머지 수를 이동시키면 된다.
그러면 최소 회수로 이동할 수 있다.

# 수를 움직이는 '과정' 에 집중하다가 아니다 싶으면, '정렬' 이 된 경우에는 어떤 특성이 있는지,
이미 정렬된 수는 무엇인지를 고민해보자.
*/

#include <bits/stdc++.h>

using namespace std;

int a[204];
int dp[204];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j] > a[i]) continue;
            if(dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << n - *max_element(dp, dp+n);
    return 0;
}