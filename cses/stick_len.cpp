#include<bits/stdc++.h>
#include <climits>
#include <cstdint>

using namespace std;

using lli = long long int;

lli solve(vector<lli> &arr) {
    lli ans = LLONG_MAX;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // maximum subarray ending at i
    vector<lli> ps(n, 0);
    for(int i=0;i<n;i++) {
        ps[i] = arr[i];
        if(i > 0) {
            ps[i] += ps[i - 1];
        }
    }
    for(int i=0;i<n;i++){
        lli left = 0;
        lli right = 0;
        lli cost = 0;
        if(i > 0) {
            left = ps[i - 1];
            cost += ((i) * arr[i]) - left;
        }
        if(i < n - 1) {
            right = ps[n-1] - ps[i];
            cost += (right - ((n - 1 - i) * arr[i]));
        }
        ans = min(ans, cost);
    }
    return ans;
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