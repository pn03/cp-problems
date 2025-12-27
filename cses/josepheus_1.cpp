#include<bits/stdc++.h>


using namespace std;


class Node {
    int val;
    Node *prev, *next;
    public:
    Node(int v) {
        this->val = v;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
};