#include <bits/stdc++.h>
using namespace std;

// insert: iterator 가 가리키는 값 앞에 삽입
/* erase: iterator 가 가리키는 값을 삭제하고 다음 원소를 가리키는 iterator 를 새로 반환.
반드시 반환되는 값을 받아 사용해야 함(NPE 위험)*/
// end: list 의 마지막 노드의 "다음"을 가리킴

int main(void) {
    list<int> L = {1,2}; // 1, 2
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    L.push_front(10); // 10 1 2
    cout << *t << "\n"; // t가 가리키는 값 = 1 을 출력
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++; // t를 한 칸 앞으로 전진, 현재 t가 가리키는 값은 2
    t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
    // 10 6 1 5, t가 가리키는 값은 5

    cout << *t << "\n"; // 5
    for(auto i : L) cout << i << ' '; // C++11 부터 지원
    cout << '\n';
    for(list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << ' ';
    }
}