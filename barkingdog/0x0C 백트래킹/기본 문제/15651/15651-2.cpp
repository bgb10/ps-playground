#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    // 같은 높이의 노드들 모두 값 설정하고, 재귀 호출
    for(int i=0; i<n; i++) {
        arr[k] = i+1;
        func(k+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}