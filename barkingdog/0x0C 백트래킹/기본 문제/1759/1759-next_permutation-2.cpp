#include <bits/stdc++.h>
using namespace std;

char input[20];
int L, C;

char vowel[] = {'a', 'e', 'i', 'o', 'u'};

void solve() {
    int output[20];
    fill(output, output + L, 0);
    fill(output + L, output + C, 1);

    int j = 0;
    int m = 0;

    do {
        for(int i=0; i<C; i++) {
            if(output[i] == 1) continue;
            if(find(vowel, vowel+5, input[i]) != vowel + 5) { // 찾은 경우
                m++;
            }
            else
                j++;
        }
        if(m>=1 && j>=2) {
            for(int i=0; i<C; i++) {
                if(output[i] == 1) continue;
                cout << input[i];
            }
            cout << '\n';
        }
        m=0;
        j=0;
    } while(next_permutation(output, output+C));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for(int i=0; i<C; i++) 
        cin >> input[i];
    sort(input, input+C);
    solve();
    return 0;
}