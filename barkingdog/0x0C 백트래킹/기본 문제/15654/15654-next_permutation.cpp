#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func() { 
    int ch[10];
    for(int i=0; i<n; i++)
        ch[i] = i;
    do {
        for(int i=0; i<m; i++)
            cout << arr[ch[i]] << ' ';
        cout << '\n';
        reverse(ch + m, ch + n);
    } while(next_permutation(ch, ch+n));
    // 순열 nPm 을 활용한 풀이
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    func();
    return 0;
}