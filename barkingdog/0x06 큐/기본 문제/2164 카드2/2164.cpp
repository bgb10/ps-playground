/*
빼는 곳과 넣는 곳이 정해져 있고, FIFO 구조이므로 큐를 사용하는 문제.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) Q.push(i);
    while(Q.size() != 1) {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front();
    return 0;
}