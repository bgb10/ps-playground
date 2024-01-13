#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int k;
    cin >> k;
    int sum = 0;
    while(k--) {
        int n;
        cin >> n;
        if(n == 0) {
            sum -= s.top();
            s.pop();
        } else {
            sum += n;
            s.push(n);
        }
    }
    cout << sum;
    return 0;
}