#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int res[10];
bool isused[10]; // 자식 노드들 사이에서 중복 확인

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    int tmp = 0; // 동일 노ㅍ이 노드들 사이에서 중복 확인
    for(int i=0; i<n; i++) {
        if(isused[i]) continue;
        if(tmp != 0 && tmp == arr[i]) continue;
        isused[i] = 1;
        res[k] = arr[i];
        tmp = arr[i];
        func(k+1);
        isused[i] = 0;
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