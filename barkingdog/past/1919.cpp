#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    // 두 문자열의 a~z 까지의 문자 개수의 delta 값을 구함.
    int cnt[26] = {};
    for(auto c : s1) {
        cnt[c-'a']++;
    }
    for(auto c : s2) {
        cnt[c-'a']--;
    }

    // delta 값을 모두 더하면 애너그램을 만들기 위해 바꿔야할 최소의 문자 개수임.
    int sum = 0;
    for(int c : cnt) {
        sum += abs(c);
    }

    cout << sum;

    return 0;
}