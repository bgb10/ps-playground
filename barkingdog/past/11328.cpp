#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 선언과 사용을 동시에 해서 햇갈리지 않도록 함.
    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int arrA[26] = {};
        int arrB[26] = {};

        for(auto c : s1) {
            arrA[c - 'a']++;
        }
        for(auto c : s2) {
            arrB[c - 'a']++;
        }

        bool possible = true;

        for(int i=0; i<26; i++) {
            if(arrA[i] != arrB[i]) possible=false;
        }

        if(possible) cout << "Possible" << "\n";
        else cout << "Impossible" << "\n";
    }

    return 0;
}