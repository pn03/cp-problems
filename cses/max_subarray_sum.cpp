#include<bits/stdc++.h>

using namespace std;

using lli = long long int;

lli solve(vector<lli> &arr) {
    lli ans = INT32_MIN;
    int n = arr.size();
    // maximum subarray ending at i
    vector<lli> dp(n, 0);
    for(int i=0;i<n;i++) {
        dp[i] = arr[i];
        if(i > 0 && dp[i] + dp[i - 1] >= dp[i]) {
            dp[i] += dp[i-1];
        }
        ans = max(ans, dp[i]);
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