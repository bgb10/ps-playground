/*
그리디와 조건 분기를 적절히 활용해야 하는 문제.

수의 순서와 상관없이 괄호를 묶을 수 있고, 최대한 큰 수를 만들어야 하므로 정렬을 활용할 수 있다.
이때 양수는 양수끼리, 음수는 음수끼리 곱하는 것이 이득이다. 
0이 나왔을 경우, 서로 짝지어지지 못한 음수(짝지어진 음수는 양수이므로)를 0 으로 곱해주면 최대값을 만드는데 도움이 된다.
위 과정을 추상화하면,
i) 내림차순 정렬된 음수 배열의 경우,
원소의 개수가 홀수일 때 큰 원소부터 2개씩 짝짓고 남은 하나의 수에는 0을 곱해준다.
원소의 개수가 짝수일 때 큰 원소부터 2개씩 짝짓는다.
-> 이는 결국 원소의 개수와 상관없이 큰 원소부터 2개씩 짝지어서 더하는 것과 동치이다.
ii) 내림차순 정렬된 양수 배열의 경우,
-> 원소의 개수와 상관없이 큰 원소부터 2개씩 짝지어서 더해주고, 남은 원소가 있다면 더해준다.
하지만, 1이 주어질 경우에 대해 고려해야 한다. 1과 양수 a를 곱하면 a이기 때문에, 1+a 보다 크지 않다.
iii) 1이 존재하는 경우,
따라서, 1인 경우는 정렬된 배열에 넣어주지 않고, 그대로 답에 더해주면 된다.

# 상황을 관찰한 후에 추상화하고, 적절히 경우를 나누면 쉽게 풀 수 있는 문제이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a;
    int ans = 0;
    vector<int> m;
    vector<int> p;
    bool is_zero_exists = false;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a < 0) m.push_back(-a);
        else if(a == 1) ans += 1; 
        else if(a > 0) p.push_back(a);
        else is_zero_exists = true;
    }
    sort(m.begin(), m.end(), greater<int>());
    sort(p.begin(), p.end(), greater<int>());
    int m_len = m.size();
    int p_len = p.size();
    for(int i=0; i<=m_len-2; i+=2) {
        ans += m[i] * m[i+1];
    }
    if(m_len % 2 == 1 && !is_zero_exists) ans -= m[m_len-1];
    for(int i=0; i<=p_len-2; i+=2) {
        ans += p[i] * p[i+1];
    }
    if(p_len % 2 == 1) ans += p[p_len-1];
    cout << ans;
	return 0;
}