#include <bits/stdc++.h>
using namespace std;

// 여기서 경우의 수가 최대 2^100 정도 될 수 있기 때문에 long long 으로도 표현이 불가
// 따라서 cpp 말고 python 으로 풀었어야 ㅋㅋ..
long long hanoiCount(int k) {
    if(k == 1) 
        return 1;
    return 2 * hanoiCount(k-1) + 1;
}

void hanoi(int k, int from, int mid, int to) {
    if(k == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    hanoi(k-1, from, to, mid);
    hanoi(1, from, mid, to);
    hanoi(k-1, mid, from, to);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << hanoiCount(k) << '\n';
    if(k <= 20) hanoi(k, 1, 2, 3);
    return 0;
}