#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;
        if(n == 0) {
            s.pop();
        } else {
            s.push(n);
        }
    }

    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}