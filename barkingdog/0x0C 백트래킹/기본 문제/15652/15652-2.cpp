#include <bits/stdc++.h>
using namespace std;

int ans[10];
int n, m;

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    // 이전 항을 인자로 전달할 필요 없이, ans 에 저장된 수를 통해 이전 항 유추 가능
    int st = k != 0 ? ans[k-1] : 1;
    for(int i=st; i<=n; i++) {
        ans[k] = i;
        func(k + 1);
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