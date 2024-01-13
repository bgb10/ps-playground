#include <bits/stdc++.h>
using namespace std;

// STL 에 있는 list는 원형 연결 리스트가 아니다.
list<int>::iterator circularNext(list<int> &l, list<int>::iterator &it) {
    return next(it) == l.end() ? l.begin() : next(it);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    list<int> p;
    for(int i=1; i<=N; i++) p.push_back(i);
    auto it = p.begin();

    cout << "<";
    while(N--) {
        for(int i=0; i<K-1; i++)
            it = circularNext(p, it);
        cout << *it;
        it = p.erase(it);
        if(N != 0) cout << ", ";
        if(it == p.end()) it = circularNext(p, it);
    }
    cout << ">";

    return 0;
}