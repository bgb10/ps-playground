#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    for(int i=0; i<k; i++)
        cin >> arr[i];
    long long left = 1;
    long long right = *max_element(arr, arr+k); // upper bound 에서 문제 생길수도 있어서 long long 으로
    long long mid;
    int ans = 1;
    while(left <= right) {
        mid = (left+right)/2;
        int cnt = 0;
        for(int i=0; i<k; i++)
            cnt += arr[i] / mid;
        // 조건에 만족하더라도 더 큰 값을 찾아보라고 했다.
        // 따라서, 더 큰 값에서 조건에 만족하지 못하는 경우가 있을 수 있으므로, 답을 항상 담고 있어야 함.
        if(cnt >= n) {
            if(mid > ans) 
                ans = mid;
            left = mid + 1;
        } 
        else right = mid - 1;
    }

    cout << ans;
    return 0;
}