#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  queue<int> Q;
  while(n--) {
    string cmd;
    cin >> cmd;
    int k;
    if(cmd == "push") {
      cin >> k;
      Q.push(k);
      continue;
    }

    if(cmd == "pop") {
      if(Q.empty()) {
        cout << -1;
      }
      else {
        cout << Q.front();
        Q.pop();
      }
    } else if(cmd == "size") {
      cout << Q.size();
    } else if(cmd == "empty") {
      cout << Q.empty();
    } else if(cmd == "front") {
      if(Q.empty()) {
        cout << -1;
      }
      else {
        cout << Q.front();
      }
    } else if(cmd == "back") {
      if(Q.empty()) {
        cout << -1;
      }
      else {
        cout << Q.back();
      }
    }

    cout << '\n';
  }
  return 0;
}