#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

// 수를 사전순으로 정렬 -> 4 3 뽑는 것고 3 4 뽑는 것이 다름 -> 순열
// nPn 을 출력하는 경우에는 쉽게 할 수 있는데, nPr 은 어떻게 구현하지?
/* nPr 구현: nPn 을 돌리면서 앞의 m개의 수는 그대로 냅두고, 뒤의 나머지 n-m 개의 수를 뒤집어서 마지막을 완성시킴.
   이를 통해 중복을 쉽게 해결할 수 있음. */

void func() {
    int ch[10];
    for(int i=0; i<n; i++) ch[i] = i+1;
    do {
        for(int i=0; i<m; i++)
            cout << ch[i] << ' ';
        cout << '\n';
        reverse(ch+m, ch+n); // 핵심! nPn 에서 앞의 m개의 수는 냅두고, 뒤의 나머지 n-m 개의 수를 뒤집는다.
    } while(next_permutation(ch, ch+n));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func();
    return 0;
}