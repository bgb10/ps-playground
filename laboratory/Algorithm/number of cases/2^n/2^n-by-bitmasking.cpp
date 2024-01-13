#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    cout << "2^n 가지 모든 경우의 수를 출력합니다. 비트마스킹을 사용합니다. 우리가 알고 있는 경우의 수랑 다르게 살짝 뒤집힌 모양입니다. \n\n";
    n = 1 << n;
    for(int i=0; i<n; i++) {
        int flag = 1;
        while(flag < n) {
            if(i & flag) cout << 1;
            else cout << 0;
            flag = flag << 1;
        }
        cout << '\n';
    }
    
    cout << "2^n 가지 모든 경우의 수를 출력합니다. 비트마스킹을 사용합니다. 우리가 익숙한 모양입니다. \n\n";
    for(int i=0; i<n; i++) {
        int flag = n >> 1;
        while(flag > 0) {
            if(i & flag) cout << 1;
            else cout << 0;
            flag = flag >> 1;
        }
        cout << '\n';
    }
    return 0;
}