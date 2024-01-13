#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    string s;
    /* 
    상황 1:
    
    숫자 숫자 (개행)
    문자열 숫자 숫자

    위 상황에서는 숫자 숫자를 입력한 후에 출력으로 인해 버퍼를 비우고, 
    이후 문자열을 입력받을 시 버퍼 안에 남아있는 개행문자로 인해 문자열이 제대로 입력되지 않는다.

    해결: 

    이를 해결하기 위해서는 버퍼 안에 남아있는 개행문자를 getline 함수로 받아야 한다.
    */
    cout << "상황 1\n";
    cin >> a >> b;
    cout << a << ' ' << b << '\n'; // 버퍼 비우기, 하지만 개행문자는 남아있음.
    // getline(cin, s); // 해결: 개행 문자도 버퍼에서 받아주면 된다. 그럼 아랫 줄에서는 정상적으로 문자열을 받는다.
    cin >> s; // 개행 문자 입력받음
    cout << s;
    cin >> a >> b; // 값이 이상하게 들어감.
    cout << a << ' ' << b << '\n';

    return 0;
}