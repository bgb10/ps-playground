/*
dp[i] : 제곱수의 합으로 표현한 항의 최소 개수
dp[i] = min(dp[i], min_element(dp[j]) + 1) : j = i - k (k는 i보다 작은 제곱수)

i를 제곱수의 합으로 표현한 항의 최소 개수는
i보다 작은 제곱수 k를 뺐을 때의 제곱수의 합으로 표현한 항의 최소 개수를 이용해서 구할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100005;

int dp[SIZE];

vector<int> squares;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int i = 1;
    while(i * i <= 100000) {
        squares.push_back(i*i);
        i++;
    }
    fill(dp, dp+SIZE, INT_MAX);
    for(int square : squares) {
        dp[square] = 1;
    }
    for(int i=1; i<=n; i++) {
        int mn = INT_MAX;
        for(int square : squares) {
            if(i - square <= 0) break;
            mn = min(mn, dp[i-square] + 1);
        }
        dp[i] = min(dp[i], mn);
    }

    cout << dp[n];
    return 0;
}