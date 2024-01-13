#include <bits/stdc++.h>
using namespace std;

char ch[20];
char ans[20];
bool isused[20];
int L, C;
int m, j;
const int vowel[5] = {'a','e','i','o','u'};

void func(int st, int k) {
    if(k == L) {
        if(m < 1 || j < 2) return;
        for(int i=0; i<L; i++)
            cout << ans[i];
        cout << '\n';
        return;
    }
    for(int i=st+1; i<C; i++) {
        ans[k] = ch[i];
        bool isvowel = false;
        for(char c : vowel) {
            if(ch[i] == c) isvowel = true;
        }
        if(isvowel) m++;
        else j++;
        func(i, k+1);
        if(isvowel) m--;
        else j--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for(int i=0; i<C; i++) 
        cin >> ch[i];
    sort(ch, ch + C);
    for(int i=0; i<C; i++) {
        ans[0] = ch[i];
        bool isvowel = false;
        for(char c : vowel) {
            if(ch[i] == c) isvowel = true;
        }
        if(isvowel) m++;
        else j++;
        func(i, 1);
        if(isvowel) m--;
        else j--;
    }
    return 0;
}