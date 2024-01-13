#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    if (s.find("d2") == std::string::npos && s.find("D2") == std::string::npos)
        cout << "unrated";
    else
        cout << "D2";
    return 0;
}