/*
LCS(Longest Common Subsequence) 을 구하는 알고리즘이다.

점화식은 아래와 같다.
LCS[i][j] = LCS[i-1][j-1] + 1 (같을 경우),
LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]) (다를 경우)

말로 풀어쓰면,
LCS[i][j]: 문자열 a의 i번째까지와 문자열 b의 j번째까지의 LCS
LCS[i][j] = LCS[i-1][j-1] + 1 (같을 경우): 문자열 a의 i번째 문자와 문자열 b의 j번째 문자가 같은 경우,
LCS[i-1][j-1] 에서 한 글자가 추가된 것과 동치
LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]) (다를 경우): 문자열 a의 i번째 문자와 문자열 b의 j번째 문자가 다른 경우,
a의 i-1까지의 문자열과 b의 j까지의 문자열의 LCS,
a의 i까지의 문자열과 b의 j-1까지의 문자열의 LCS,
중 큰 값을 고르면 된다.
*/
#include <bits/stdc++.h>
using namespace std;

int LCS[1005][1005];

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

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            int si = i - 1;
            int sj = j - 1;
            if (a[si] == b[sj])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);

            if (LCS[i][j] > lcs_size) {
                lcs_size = LCS[i][j];
            }
        }
    }

    cout << lcs_size << '\n';

    return 0;
}