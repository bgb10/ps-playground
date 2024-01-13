/*
Compare 함수를 작성해서 2 번의 stable_sort 없이 한번에 정렬되도록 만들었다.
x 를 우선해서 정렬하고, x 가 같을 경우 y 를 우선해서 정렬하도록 한다.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> V;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.X == p2.X) {
        return p1.Y < p2.Y;
    }

    return p1.X < p2.X;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        V.push_back({x, y});
    }
    sort(V.begin(), V.end(), compare);
    for(auto i : V) {
        cout << i.X << ' ' << i.Y << '\n';
    }
    return 0;
}