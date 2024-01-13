#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int res[10];
bool isused[10]; // 자식 노드들 사이에서 중복 확인

void func(int k, int at) {
    res[k] = arr[at];
    k++;
    if(k == m) {
        for(int i=0; i<m; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0; // 동일 높이 노드에서 중복 확인
    for(int i=0; i<n; i++) {
        if(tmp == arr[i] || isused[i]) continue;
        tmp = arr[i];
        isused[i] = true;
        func(k, i);
        isused[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int tmp = 0;
    for(int i=0; i<n; i++) {
        if(tmp == arr[i]) continue;
        tmp = arr[i];
        isused[i] = true;
        func(0, i);
        isused[i] = false;
    }
    return 0;
}