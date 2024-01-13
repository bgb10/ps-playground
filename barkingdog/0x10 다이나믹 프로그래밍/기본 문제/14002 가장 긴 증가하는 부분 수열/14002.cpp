/*
DP 문제로 유명한 LIS 유형 중, 부분 수열의 길이 뿐만 아니라 수열 자체를 저장해야 하는 문제.

따로 수열을 저장할 수 있는 배열(dpv)를 두고, 
LIS 를 구할 때 dp 배열의 길이를 갱신할 때마다 dpv 도 갱신해주면 된다. 
*/

#include <bits/stdc++.h>
using namespace std;

int a[1004];
int dp[1004];
vector<int> dpv[1004];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[i] = 1;
        dpv[i].push_back(a[i]);
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    vector<int> tmp;
                    tmp.insert(tmp.end(), dpv[j].begin(), dpv[j].end());
                    tmp.push_back(a[i]);
                    dpv[i] = tmp;
                }
            }
        }
    }
    int ansidx = max_element(dp, dp+1004) - dp;
    cout << dp[ansidx] << '\n';
    for(int i : dpv[ansidx]) {
        cout << i << ' ';
    }
	return 0;
}