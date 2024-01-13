/*
주의1: STL의 Sort 는 stable-sort 가 아니다!
주의2(특히 중요): 비교함수에서 두 값이 같을 때에는 false 를 반환해야 한다. 즉, 등호를 사용하면 안된다.
주의3: 비교함수의 인자로 클래스 객체 또는 stl 자료구조를 전달할 시 reference 를 전달하자. (복사비용)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> V;

void printVector() {
    for(auto i : V) {
        cout << i << '\n';
    }
}

bool comparatorfunc(int a, int b) {
    // a 가 b 의 뒤에 있어야 할 경우 true, 아니면 false 반환
    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        V.push_back(x);
    }
    // 오름차순 정렬
    cout << "ascending: " << '\n';
    sort(V.begin(), V.end());
    printVector();
    // 내림차순 정렬
    cout << "descending: " << '\n';
    sort(V.begin(), V.end(), greater<int>());
    printVector();
    // comparator 함수를 사용해 정렬 기준 직접 정의
    cout << "custom: " << '\n';
    sort(V.begin(), V.end(), comparatorfunc);
    printVector();
    return 0;
}