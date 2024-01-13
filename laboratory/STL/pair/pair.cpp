#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> a = make_pair(1, 2);
    pair<int, int> b = {3, 4};

    cout << a.first << " " << a.second << '\n';
    cout << b.first << " " << b.second << '\n';

    b.first = 1;
    cout << (a < b); 

    return 0;
}