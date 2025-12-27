#include<iostream>
#include<vector>

using namespace std;

int solve(vector<char> &arr, int len) {
    int ct = 0;
    int ans = 0;
    // vector<int> gaps;
    int three = 0;
    int sum = 0;
    for(int i=0;i<len;i++) {
        auto ch = arr[i];
        if(ch == '.') {
            ct += 1;
        }else {
            if(ct > 2) {
                three = 1;
            }
            if(ct > 0) {
                sum += ct;
                // gaps.push_back(ct);
            }
            ct = 0;
        }
    }
    if(ct > 0) {
        sum += ct;
    }
    if(ct > 2) {
        three = 1;
    }

    if(three > 0) {
        return 2;
    } else {
        return sum;
    }
}
int main() {
    vector<char> arr(101, ' ');
    int t;
    cin>>t;
    while(t-- > 0) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        cout<<solve(arr, n)<<endl;
    }
    return 0;
}