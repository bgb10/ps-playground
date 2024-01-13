#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);

    int N, a[10] = {}, ans = 1;
    cin >> N;

    while(N) {
        a[N%10]++;
        N/=10;
    }

    for(int i=0; i<10; i++) {
        if(i==6 || i==9) continue;
        ans = max(ans, a[i]);
    }

    //올림을 이렇게 할 수도 있구나.
    ans = max(ans, (a[6]+a[9]+1)/2);

    cout << ans;

   return 0;
}