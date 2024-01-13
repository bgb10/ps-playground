#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos++] = x;
}

int pop(){
    if(pos == 0) return -1;
    return dat[--pos];
}

int top(){
    if(pos == 0) return -1;
    return dat[pos-1];
}

int main(void) {

    int N;
    cin >> N;

    string cmd;
    int num;

    while(N--) {
        cin >> cmd;

        if(!cmd.compare("push")) {
            cin >> num;
            push(num);
        } else if(!cmd.compare("pop")) {
            cout << pop() << "\n";
        } else if(!cmd.compare("size")) {
            cout << pos << "\n";
        } else if(!cmd.compare("empty")) {
            cout << (pos == 0 ? 1 : 0) << "\n";
        } else { // top
            cout << top() << "\n";
        }
    }
}