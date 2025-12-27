#include<bits/stdc++.h>
#include <climits>

using namespace std;

using lli = long long int;

lli solve(vector<lli> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if(arr[0] != 1) {
        return 1;
    }
    lli largest_possible = 1;
    for(int i=1;i<n;i++) {
        auto curr = arr[i];
        auto next_req = largest_possible + 1;
        if(curr <= next_req) {
            // we can create upto curr + sum_so_far.
            largest_possible += curr;
        } else {
            // largest_possible = 5, and curr = 7
            // we can create 11. but is it possible to create 6 ?
            // we can create 7 but 6 cannot be created.
            return next_req;
        }
    }
    return largest_possible + 1;
}

int main() {
    int n;
    cin>>n;
    vector<lli> arr(n, 0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
}