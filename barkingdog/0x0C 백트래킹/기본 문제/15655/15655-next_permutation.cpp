#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func() { 
    int ch[10];
    fill(ch, ch+m, 0);
    fill(ch+m, ch+n, 1); 
    do {
        for(int i=0; i<n; i++) {
            if(ch[i] == 0) 
                cout << arr[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(ch, ch+n));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n); //next_permutation 은 정렬되어 있다는 전제하에 사용 가능!
    func();
    return 0;
}