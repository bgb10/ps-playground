#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[5] = {1,2,3,4,5};
    cout << "최대 값의 주소: " << max_element(arr, arr+5) << '\n';
    cout << "최대 값: " << *max_element(arr, arr+5) << '\n';
    return 0;
}