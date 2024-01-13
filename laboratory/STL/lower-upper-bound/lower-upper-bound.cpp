#include <bits/stdc++.h>
using namespace std;

int a[10000];

// lower, upper bound 는 이진 탐색을 기반으로 구현된다.
// 따라서, 배열의 각 요소들이 미리 정렬되어있어야 한다.
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    // 1. Lower bound, Upper bound 는 배열이 정렬되어 있다고 가정한다.
    cout << "오름차순의 경우: " << '\n';
    sort(a, a+n); 

    // 2. lower, upper bound 는 [lower, upper) 에 대한 주소값을 제공한다. 
    int up, down;
    cout << "하한?: ";
    cin >> down;
    cout << "상한?: ";
    cin >> up;

    cout << "lower bound: " << *lower_bound(a, a+n, down) << '\n';
    cout << "upper bound: " << *upper_bound(a, a+n, up) << '\n';
    // 인덱스를 알고 싶다면 주소값을 빼주면 된다.
    cout << "lower bound의 인덱스: " << lower_bound(a, a+n, down) - a << '\n';
    cout << "upper bound의 인덱스: " << upper_bound(a, a+n, up) - a << '\n';

    // 3. lower-upper bound 에서 4번째 인자에 정렬 형태가 주어지지 않을 경우, 오름차순으로 가정한다.
    // 만약 배열이 오름차순이 아닐 경우 정렬 형태를 전달해주어야 한다.
    cout << "내림차순의 경우: " << '\n';
    sort(a, a+n, greater<int>()); // 내림차순 정렬

    cout << "하한?: ";
    cin >> down;
    cout << "상한?: ";
    cin >> up;

    cout << "lower bound: " << *lower_bound(a, a+n, down, greater<int>()) << '\n';
    cout << "upper bound: " << *upper_bound(a, a+n, up, greater<int>()) << '\n';
    cout << "lower bound의 인덱스: " << lower_bound(a, a+n, down, greater<int>()) - a << '\n';
    cout << "upper bound의 인덱스: " << upper_bound(a, a+n, up, greater<int>()) - a << '\n';
    return 0;
}