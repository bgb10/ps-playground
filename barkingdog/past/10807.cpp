#include <bits/stdc++.h>
using namespace std;


int s[7][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    int S, Y;
    int cnt = 0;

    cin >> N >> K;

    for(int i=0; i<N; i++) {
        cin >> S >> Y;

        s[Y][S]++;
    }

    for(int i=1; i<=6; i++) {
        for(int j=0; j<=1; j++) {
            cnt += (s[i][j] + K - 1) / K; //어떻게 정수 올림 처리를 하는가? 에 대한 것.
        }
    }

    cout << cnt;

    return 0;
}