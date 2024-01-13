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
        // for(int i=0; i<K-1; i++) it++; // 이건 iterator 가 list 범위를 지났기 때문에 터지는 것
        for(int i=0; i<K-1; i++) it = circularNext(p, it);
        cout << *it;
        if(N != 0) cout << ", ";
        it = p.erase(it);
        // 원형 연결 리스트가 아니기 때문에 it 이 리스트의 끝이라면 처음으로 돌려놔야 함.
        // 만약 돌려놓지 않으면 다음 loop 때의 circularNext로 인해 K-1 칸만 이동하게 됨.
        if(it == p.end()) it = p.begin(); 
    }
    cout << ">";

    return 0;
}