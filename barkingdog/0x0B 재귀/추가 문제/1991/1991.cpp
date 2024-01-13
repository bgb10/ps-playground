#include <bits/stdc++.h>
using namespace std;

// 각 인덱스가 A ~ Z 지칭
char lefts[200];
char rights[200];

void preorder(char root) {
    if(root == '.')
        return;
    cout << root;
    preorder(lefts[root]);
    preorder(rights[root]);
}

void inorder(char root) {
    if(root == '.')
        return;
    inorder(lefts[root]);
    cout << root;
    inorder(rights[root]);
}

void postorder(char root) {
    if(root == '.')
        return;
    postorder(lefts[root]);
    postorder(rights[root]);
    cout << root;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    char root, left, right;
    for(int i=0; i<T; i++) {
        cin >> root >> left >> right;
        lefts[root] = left;
        rights[root] = right;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}