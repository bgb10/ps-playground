#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int bn = ~n + 1;
    int k = 32;
    int dcnt = 0;
    while(k--) {
        int mask = 1 << k;
        bool maskA = mask & n;
        bool maskB = mask & bn;
        if(maskA != maskB) dcnt++; 
    }
    cout << dcnt;
    return 0;
}