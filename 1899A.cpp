#include<iostream>

using namespace std;


int main() {
    int t;
    cin>>t;
    while(t-- > 0) {
        int n;
        cin>>n;
        int rem = n%3;
        if(rem == 1 || rem == 2) {
            cout<<"First" <<endl;
        } else {
            cout<<"Second" <<endl;
        }
    }
    return 0;
}