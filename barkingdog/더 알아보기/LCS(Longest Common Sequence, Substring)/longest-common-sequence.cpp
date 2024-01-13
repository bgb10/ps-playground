/*
LCS(Longest Common Subsequence) 을 구하는 알고리즘이다.

점화식은 아래와 같다.
LCS[i][j] = LCS[i-1][j-1] + 1 (같을 경우),
LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]) (다를 경우)

여기서는 LCS의 길이 뿐만 아니라 LCS 문자열을 직접 구한다.
# 주의!!!!! LCS의 인덱스는 1-indexed, substring 의 인덱스는 0-indexed 임에 주의하자.
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
    for (int i = 0; i < 1000; i++) {
        LCS[i][0] = 0;
        LCS[0][i] = 0;
    }

    // LCS 개수 알고리즘 진행
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

    cout << "LCS Size: " << lcs_size << '\n';

    // LCS 문자열 구하는 알고리즘 진행
    string ans;

    int sti = a.length();
    int stj = b.length();
    while (LCS[sti][stj] != 0) {
        if (LCS[sti][stj] == LCS[sti - 1][stj]) {
            sti = sti - 1;
        } else if (LCS[sti][stj] == LCS[sti][stj - 1]) {
            stj = stj - 1;
        } else {
            ans += a[sti - 1];
            sti = sti - 1;
            stj = stj - 1;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}