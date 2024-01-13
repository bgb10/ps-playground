#include <bits/stdc++.h>
using namespace std;

int numbers[10];
double set_numbers[10] = {1,1,1,1,1,1,2,1,1,0};

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;

    while(N > 0) {
        int t = N%10;
        if(t == 9) t = 6;
        numbers[t]++;
        
        N/=10;
    }

    double max = 0.0;

    for(int i=0; i<9; i++) {
        if(max < numbers[i]/set_numbers[i]) max = numbers[i]/set_numbers[i];
    }

    cout << (int)ceil(max);

   return 0;
}