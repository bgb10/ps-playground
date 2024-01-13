/*
다이나믹 프로그래밍 기초 문제. DP의 개념을 학습하기 좋은 문제다.

DP는 전체 문제에 대한 최적해를 구할 때 부분 문제에 대한 최적해를 쌓아올려서 답을 구하는 방법론을 말한다.
전체 문제의 최적해는 "n 을 1로 만들 때 드는 최소 횟수" 이다.
해당 문제에 대한 부분 최적해를 고민해보자면, "i 를 1로 만들 때 드는 최소 횟수" 이다.
예를 들면 더욱 쉽게 이해할 수 있다.
12를 1로 만들 때 드는 최소 횟수를 구하기 위해서는,
(12/2)을 1로 만들 때 드는 최소 횟수, (12/3)을 1로 만들 때 드는 최소 횟수, (12-1)을 1로 만들 때 드는 최소 횟수
중 최소값을 구하고, 거기에 1을 더한게 곳 12를 1로 만들 때 드는 최소 횟수이다.
부분 문제의 최적해가 이미 풀려있다는 가정하에, 또 다른 부분 문제의 최적해를 구할 수 있는 것이다.
이때 가장 처음 쌓은 부분 문제의 최적해는 1를 1로 만들 때의 최적해인 0 일 것이다.(초기항)

정리하자면,
전체문제: n 을 1로 만들 때 드는 최소해
부분문제: i 를 1로 만들 때 드는 최소해
부분문제 사이의 점화식: x[i] = min(x[i/2], x[i/3], x[i-1]) + 1 (나눠질 경우)
초기항: x[1] = 0;

# DP의 개념을 정확히 이해하고, 전체 문제에 대한 최적 부분 문제(Optimal Structure)가 뭔지 고민하자.
# 해당 문제는 BFS 의 "숨바꼭질" 문제와 굉장히 유사하다. BFS 로도 풀이할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int x[1000004];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    x[1] = 0;
    for(int i=2; i<=n; i++) {
        int mn = x[i-1];
        if(i % 2 == 0) mn = min(mn, x[i/2]);
        if(i % 3 == 0) mn = min(mn, x[i/3]);
        x[i] = mn + 1;
    }
    cout << x[n];
	return 0;
}