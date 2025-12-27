#include<vector>
#include<iostream>

using namespace std;

int solve(vector<int> &arr, int len, int x) {
    int mx = 0;
    int prev = 0;
    for(int i=0;i<len;i++) {
        auto curr = arr[i];
        mx = max(mx, curr - prev);
        prev = curr;
    }
    mx = max(mx, 2 * (x - prev));
    return mx;
}

int main() {
    int t;
    cin>> t;
    vector<int> arr(1000, 0);
    while(t-- > 0) {
        int n, x;
        cin>>n>>x;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        cout<<solve(arr, n, x) <<endl;
    }
    return 0;
}