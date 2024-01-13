#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int res[10];
// 자식 노드들 사이에는 중복 확인 불필요

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0; // 동일 높이 노드들 사이에서 중복 확인
    for(int i=0; i<n; i++) {
        if(tmp != 0 && tmp == arr[i]) continue;
        res[k] = arr[i];
        tmp = arr[i];
        func(k+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    func(0);
    return 0;
}