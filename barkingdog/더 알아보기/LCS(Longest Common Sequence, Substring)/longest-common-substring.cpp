/*
LCS(Longest Common Substring) 을 구하는 알고리즘이다.

점화식은 아래와 같다.
LCS[i][j] = LCS[i-1][j-1] + 1 (같을 경우),
LCS[i][j] = 0 (다를 경우)
*/
#include <bits/stdc++.h>
using namespace std;

int LCS[1000][1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;

    // 0으로 margin 채우기
    for (int i = 0; i <= a.length(); i++) {
        LCS[i][0] = 0;
        LCS[0][i] = 0;
    }

    // LCS 알고리즘 진행
    int lcs_size = 0;
    int lcs_i = 0;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            int si = i - 1;
            int sj = j - 1;
            if (a[si] == b[sj])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = 0;

            if (LCS[i][j] > lcs_size) {
                lcs_size = LCS[i][j];
                lcs_i = i;
            }
        }
    }

    cout << "LCS Size: " << lcs_size << '\n';
    cout << a.substr(lcs_i - lcs_size, lcs_size);

    return 0;
}