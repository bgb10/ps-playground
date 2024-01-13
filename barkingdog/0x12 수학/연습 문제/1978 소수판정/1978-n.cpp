// O(N) 의 소수판정법

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cin >> k;
        bool isprime = true;
        if(k == 1) isprime = false;
        for(int j=2; j<k; j++) {
            if(!(k % j)) {
                isprime = false;
                break;
            }
        }
        if(isprime) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}