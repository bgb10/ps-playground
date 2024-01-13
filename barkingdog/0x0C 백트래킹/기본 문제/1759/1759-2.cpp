#include <bits/stdc++.h>
using namespace std;

char input[20];
char output[20];
char vowel[] = {'a', 'e', 'i', 'o', 'u'};
int L, C;

// 오름차순이 보장되어야 하기 때문에 isused 와 함께 st 도 사용해야 한다.
// 사실 st 로 인해 자식, 부모 노드간에 중복이 사라지기 때문에 isused 를 사용하지 않아도 된다.
void solve(int k, int st) {
    if(k == L) {
        int m=0, j=0;
        for(int i=0; i<L; i++) {
            if(find(vowel, vowel + 5, output[i]) != vowel + 5)
                m++;
            else
                j++;
        }
        if(m >= 1 && j >= 2) {
            for(int i=0; i<L; i++)
                cout << output[i];
            cout << '\n';
        }
    }
    for(int i=st; i<C; i++) {
        output[k] = input[i];
        solve(k+1, i+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for(int i=0; i<C; i++)
        cin >> input[i];
    sort(input, input + C);
    solve(0, 0);
    return 0;
}